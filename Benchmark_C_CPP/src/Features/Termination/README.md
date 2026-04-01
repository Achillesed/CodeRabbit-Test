# 循环

## 数据流路径上存在多个大循环（和条件无关）

* `Features_Termination_Loop_Big_Loop_irrelevance.c`:  如果存在大循环的路径，是否会选择跳过分析该路径。
    > If the widen-loops option is not set then we model only 4 iterations of loops and then the analyzer stops on that path by putting a sink node. [CSA issue链接](https://github.com/llvm/llvm-project/issues/58621)。  
    >CSA如果打开widen-loops选项，不会出现FP

* `Features_Termination_Loop_irrelevance.c`: 简单的嵌套循环，CSA如果打开widen-loops选项，会出现FP，[issue链接](https://github.com/llvm/llvm-project/issues/58644)

* `Features_Termination_Loop_Range_Based_Loop.cpp`: 考察range-based for loop的支持情况，如果默认所有range-based for loop都存在0-iteration的情况，那么在该样例中就会出现FP。[issue链接](https://github.com/llvm/llvm-project/issues/64584)

# 递归