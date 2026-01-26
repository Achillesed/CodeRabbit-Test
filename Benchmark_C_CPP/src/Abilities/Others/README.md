# 约束类型

## Range-based solver may not support

* `Others_ConstraintSolver_UnionInt.c` : 属于CSA求解器会误报的情况，[issue链接](https://github.com/llvm/llvm-project/issues/60026)。（不确定CSA启用Z3 solver选项是否可以避免）
* `Others_ConstraintSolve_SymSym_RelOps.c`: good1中的约束range-based solver无法求解，后面又发现CSA求解器中激进的垃圾回收会导致bug，[good1相关说明](https://github.com/llvm/llvm-project/issues/62215)，[good2相关说明](https://discourse.llvm.org/t/range-based-solver-and-eager-symbol-garbage-collection/74670)。（目前修复该bug的PR仍未合并）

## Crash case
* `Other_Crash.cpp`: https://github.com/llvm/llvm-project/issues/71174