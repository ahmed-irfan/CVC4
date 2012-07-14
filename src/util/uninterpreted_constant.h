/*********************                                                        */
/*! \file uninterpreted_constant.h
 ** \verbatim
 ** Original author: mdeters
 ** Major contributors: none
 ** Minor contributors (to current version): none
 ** This file is part of the CVC4 prototype.
 ** Copyright (c) 2009-2012  The Analysis of Computer Systems Group (ACSys)
 ** Courant Institute of Mathematical Sciences
 ** New York University
 ** See the file COPYING in the top-level source directory for licensing
 ** information.\endverbatim
 **
 ** \brief Representation of constants of uninterpreted sorts
 **
 ** Representation of constants of uninterpreted sorts.
 **/

#include "cvc4_public.h"

#pragma once

#include "expr/type.h"
#include <iostream>

namespace CVC4 {

class CVC4_PUBLIC UninterpretedConstant {
  const Type d_type;
  const Integer d_index;

public:

  UninterpretedConstant(Type type, Integer index) throw() :
    d_type(type),
    d_index(index) {
    CheckArgument(type.isSort(), type, "uninterpreted constants can only be created for uninterpreted sorts, not `%s'", type.toString().c_str());
    CheckArgument(index >= 0, index, "index >= 0 required for uninterpreted constant index, not `%s'", index.toString().c_str());
  }

  ~UninterpretedConstant() throw() {
  }

  Type getType() const throw() {
    return d_type;
  }
  const Integer& getIndex() const throw() {
    return d_index;
  }

  bool operator==(const UninterpretedConstant& uc) const throw() {
    return d_type == uc.d_type && d_index == uc.d_index;
  }
  bool operator!=(const UninterpretedConstant& uc) const throw() {
    return !(*this == uc);
  }

  bool operator<(const UninterpretedConstant& uc) const throw() {
    return d_type < uc.d_type ||
           (d_type == uc.d_type && d_index < uc.d_index);
  }
  bool operator<=(const UninterpretedConstant& uc) const throw() {
    return d_type < uc.d_type ||
           (d_type == uc.d_type && d_index <= uc.d_index);
  }
  bool operator>(const UninterpretedConstant& uc) const throw() {
    return !(*this <= uc);
  }
  bool operator>=(const UninterpretedConstant& uc) const throw() {
    return !(*this < uc);
  }

};/* class UninterpretedConstant */

std::ostream& operator<<(std::ostream& out, const UninterpretedConstant& uc) CVC4_PUBLIC;

/**
 * Hash function for the BitVector constants.
 */
struct CVC4_PUBLIC UninterpretedConstantHashStrategy {
  static inline size_t hash(const UninterpretedConstant& uc) {
    return TypeHashFunction()(uc.getType()) * IntegerHashStrategy::hash(uc.getIndex());
  }
};/* struct UninterpretedConstantHashStrategy */

}/* CVC4 namespace */
