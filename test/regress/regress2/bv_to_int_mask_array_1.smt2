; COMMAND-LINE: --solve-bv-as-int --bvand-integer-granularity=1 --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE: --solve-bv-as-int --bvand-integer-granularity=1 --solve-bv-as-int-mode=iand --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE: --solve-bv-as-int --bvand-integer-granularity=1 --solve-bv-as-int-mode=iand --iand-mode=sum --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE: --solve-bv-as-int --bvand-integer-granularity=1 --solve-bv-as-int-mode=iand --iand-mode=bitwise --no-check-models  --no-check-unsat-cores --no-check-proofs
; EXPECT: unsat
(set-logic ALL)
(declare-fun A () (Array Int Int))
(declare-fun f ((_ BitVec 3)) Int)
(declare-fun x () (_ BitVec 3))
(declare-fun y () (_ BitVec 3))
(assert (distinct (select A (f (bvand x y))) (select A (f (bvor x y)))))
(assert (= x y))
(check-sat)
