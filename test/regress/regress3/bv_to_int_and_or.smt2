; COMMAND-LINE:  --bvand-integer-granularity=1 --solve-bv-as-int=sum  --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE:  --bvand-integer-granularity=1 --solve-bv-as-int=iand --iand-mode=sum --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE:  --bvand-integer-granularity=1 --solve-bv-as-int=iand --iand-mode=bitwise --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE:  --bvand-integer-granularity=1 --solve-bv-as-int=iand --no-check-models  --no-check-unsat-cores --no-check-proofs
; COMMAND-LINE:  --bvand-integer-granularity=2 --solve-bv-as-int=sum  --no-check-models  --no-check-unsat-cores --no-check-proofs
; EXPECT: unsat
(set-logic QF_BV)
(declare-fun a () (_ BitVec 4))
(declare-fun b () (_ BitVec 4))
(assert (bvult (bvor a b) (bvand a b)))
(check-sat)
