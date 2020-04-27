/*********************                                                        */
/*! \file iand_solver.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Andrew Reynolds
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2019 by the authors listed in the file AUTHORS
 ** in the top-level source directory) and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief Solver for integer and (IAND) constraints
 **/

#ifndef CVC4__THEORY__ARITH__IAND_SOLVER_H
#define CVC4__THEORY__ARITH__IAND_SOLVER_H

#include <map>
#include <vector>

#include "context/cdhashset.h"
#include "expr/node.h"
#include "theory/arith/theory_arith.h"
#include "theory/arith/nl_model.h"

namespace CVC4 {
namespace theory {
namespace arith {

/** Integer and solver class
 *
 */
class IAndSolver
{
  typedef context::CDHashSet<Node, NodeHashFunction> NodeSet;
 public:
  IAndSolver(TheoryArith& containing, NlModel& model);
  ~IAndSolver();

  /** init last call
   *
   * This is called at the beginning of last call effort check, where
   * assertions are the set of assertions belonging to arithmetic,
   * false_asserts is the subset of assertions that are false in the current
   * model, and xts is the set of extended function terms that are active in
   * the current context.
   */
  void initLastCall(const std::vector<Node>& assertions,
                    const std::vector<Node>& false_asserts,
                    const std::vector<Node>& xts);
  //-------------------------------------------- lemma schemas
  /** check initial refine
   *
   * Returns a set of valid theory lemmas, based on simple facts about IAND.
   *
   * Examples where iand is shorthand for (_ iand k):
   *
   * 0 <= iand(x,y) < 2^k
   * iand(x,y) = iand(y,x)
   * iand(x,y) <= x
   * iand(x,y) <= y
   * 
   * This should be a heuristic incomplete check that only introduces a
   * small number of new terms in the lemmas it returns.
   */
  std::vector<Node> checkInitialRefine();
  /** check full refine 
   * 
   * This should be a complete check that returns at least one lemma to
   * rule out the current model.
   */
  std::vector<Node> checkFullRefine();

  //-------------------------------------------- end lemma schemas
 private:
  // The theory of arithmetic containing this extension.
  TheoryArith& d_containing;
  /** Reference to the non-linear model object */
  NlModel& d_model;
  /** commonly used terms */
  Node d_zero;
  Node d_one;
  Node d_neg_one;
  Node d_two;
  Node d_true;
  Node d_false;
  /** IAND terms that have been given initial refinement lemmas */
  NodeSet d_initRefine;
  /** all IAND terms, for each bit-width */
  std::map< unsigned, std::vector< Node > > d_iands;
}; /* class IAndSolver */

}  // namespace arith
}  // namespace theory
}  // namespace CVC4

#endif /* CVC4__THEORY__ARITH__IAND_SOLVER_H */
