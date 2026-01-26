# 环境建模（Env）
* `Abilities_Env_sink_stdlib.c` ：sink点在库函数里面，未处理不当会产生漏报。
* `Abilities_Env_source_stdlib.c`：source点在库函数里面，未处理不当会产生漏报。
* `Abilities_Env_source_stdlib.c`：source点在库函数里面，未处理不当会产生漏报。
* `Abilities_Env_stdlib_Cond.c`：测试strlen库函数建模是否准确，如果准确不会产生误报。
* `Abilities_Env_Strcpy.c`：测试strlen库函数建模是否准确和Strcpy是否处理得体，如果精确不会产生误报。
* `Abilities_Env_Teriminator.c`：测试退出函数和跨函数的退出函数是否处理到位，处理不当会产生误报。
## 标准库（Standard）
* `Abilities_Env_Std_Span.cpp`： 测试C++20中`std::span`的内存建模情况。处理不到位，会触发样例中的除零FP。from https://github.com/llvm/llvm-project/issues/64584
* `Abilities_Env_Std_Container.cpp`: C++容器操作，如果对容器没有建模会产生漏报，处理不当会有误报。
* `Abilities_Env_Qt.cpp`： 其中包括常见的Qt库内的容器操作，如果对容器没有建模会产生漏报，处理不当会有误报。。