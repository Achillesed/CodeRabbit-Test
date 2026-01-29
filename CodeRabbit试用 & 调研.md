



# CodeRabbit试用 & 调研

## 结论

1.CodeRabbit 适用于研发团队第一步把关PR的质量：生成PR总结和注释；消除在PR中存在的编码低级错误；增量审查；缩短人工审查PR的等待时间；初步审查缺陷；对话讨论变更。

2.CodeRabbit 工具不追求更高的基准分数或依赖传统指标，而是通过自定义评估方法关注 AI 系统在实际工程环境中的表现，在功能试用时也体现到这点：好用（有详细且合理的潜在问题和修复方案分析）但默认配置下缺陷报出率偏低（需要通过添加自定义审查指令或持续运行来丰富其智能学习库）。

3.CodeRabbit 在GitHub 或 VsCode 插件中直接进行PR，方便。

不需要打开专门的网页或学习新工具，直接在 GitHub/GitLab 评论区或VSCode开发界面就能完成对话和代码修复。自动生成的变更摘要和逻辑演练（Walkthrough）让接手审查的同事能瞬间读懂改动意图，极大地缩短了接手的认知门槛。

4.**CodeRabbit 目前优化的是"快速 PR 审查"场景，而不是"安全审计扫描"场景**。coderabbit的逻辑似乎并不追求在 Benchmark（基准测试）中拿高分，而是更关注在真实工程里的实用感。但在实际测试中，**让人失望的是，它漏掉了一些非常显而易见的（Low-hanging fruits）缺陷**。像基础的空指针解引用和明显的数组越界这类“送分题”，在默认配置下都没有报出来。**这种深度的缺失在 clib 项目实测中表现得尤为直观：其报出的缺陷大多处于边缘位置，对于 Coverity 所定义的关键缺陷，命中率甚至不足 1%。** 这说明它的默认策略为了降低误报可能过于保守，或者为了更快的检出速度忽略了分析深度。如果想要更高的检出率，必须手动添加自定义审查指令，或者依赖它长时间运行后的智能库积累。

- ✅ **日常代码审查**: 合适（快速反馈）
- ❌ **安全审计/Benchmark测试**: 不充分（需要深度扫描）

## 测试结果

### SAGA_CheckerCase测试集

**用于测试Coderabbit审计的缺陷种类覆盖率。**

详细测试结果：https://github.com/Achillesed/CodeRabbit-Test/pull/1

上传了 114 个 SAGA全量模版 规则代码示例文件（1个文件中包含1个漏洞代码示例和1个修正代码示例）【包括**安全功能**，**表达式比较错误**，**并发性问题**，**缓冲区溢出**，**资源泄漏**等类型】并进行PR，记录在Github页面上生成的对于此PR的初步代码审查结果。

额外正报：1.高危标 *（区分数据追踪类  *+ 和 匹配类 *-）

​					2.非高危 代码规范类标 /					

​					3.非高危逻辑、语义理解标 !

#### 测试结果

| **规则类别**         | **规则 ID**                       | **规则名称**                                   | 命中率 | 额外正报 | 误报 |
| -------------------- | --------------------------------- | ---------------------------------------------- | ------ | -------- | ---- |
| **安全功能**         | WEAK_RAND_S                       | 使用密码学上弱的伪随机数生成器（PRNG）         | 0      | 3/       |      |
| **安全功能**         | DANGER_ENC_FUN_S                  | 使用已破解或危险的加密算法                     | 0      | 1*-      |      |
| **安全功能**         | OS_CMD_INJECTION_S                | 操作系统命令注入                               | 0      | 0        |      |
| **表达式比较错误**   | UNSIGNED_COMPARE_S                | 无符号值与 0 做了比较                          | 0      | 0        |      |
| **表达式比较错误**   | BAD_COMPARE_STR_S                 | 指针与字符串常量做了比较                       | 0      | 1!       |      |
| **表达式比较错误**   | ARRAY_COMPARE                     | 数组与 0 做了比较                              | 0      | 0        |      |
| **表达式比较错误**   | FLOATING_POINT_EQUALITY_S         | 错误比较浮点表达式                             | 0      | 0        |      |
| **表达式比较错误**   | BAD_COMPARE_NULL_S                | 与 NULL 做了不相等比较                         | 0      | 1!       |      |
| **表达式比较错误**   | BAD_COMPARE_NOTOP_S               | 非正常值与逻辑否定运算符做了比较               | 0      | 1/       |      |
| **并发性问题**       | CONC_NO_UNLOCK_S                  | 锁定不当——缺少解锁                             | 0      | 0        |      |
| **并发性问题**       | CONC_NO_LOCK_S                    | 锁定不当——缺少锁                               | 0      | 0        |      |
| **并发性问题**       | CONC_DUNLOCK_S                    | 锁定不当——双重解锁                             | 0      | 1/       |      |
| **并发性问题**       | CONC_DLOCK_S                      | 锁定不当——双重锁定                             | 0      | 0        |      |
| **并发性问题**       | RACE_CONDITION_WITHIN_THREAD_S    | 线程之间不应存在数据争用                       | 1      | 3/       |      |
| **并发性问题**       | DEAD_MUTEX_S                      | 线程之间不应有死锁 [并发锁次序][未知锁]        | 0      | 2/       |      |
| **并发性问题**       | DYN_CREATE_THREAD_S               | 不应创建任何动态线程                           | 0      | 2/       |      |
| **并发性问题**       | RECURSIVE_LOCK_S                  | 非递归 mutex 不得递归锁定                      | 0      | 1/       |      |
| **并发性问题**       | NOT_MATCH_CONDVAR_MUTEX_S         | 一个条件变量至多与一个 mutex 对象相关联        | 0      | 0        |      |
| **并发性问题**       | INIT_THREAD_BY_THREAD_S           | 线程同步对象在访问之前应先初始化               | 0      | 0        |      |
| **并发性问题**       | DYN_CREATE_THREADPTR_S            | 在访问线程之前应先创建线程特有存储指针         | 0      | 1/       |      |
| **并发性问题**       | INCORRECT_USE_THREAD_S            | 线程对象只能由相应的标准库访问                 | 0      | 1/       |      |
| **并发性问题**       | JOIN_DETACH_S                     | 先前连接或分离的线程不应再次连接或分离         | 0      | 2/       |      |
| **并发性问题**       | DESTORY_BY_THREAD_S               | 线程同步对象不应该被线程销毁                   | 0      | 1/       |      |
| **并发性问题**       | THREAD_MISSING_UNLOCK_S           | 由线程锁定的所有互斥对象应由同一线程显式解锁   | 0      | 1/       |      |
| **不安全的数据处理** | TAINTED_SCALAR_BOUND_S            | 不可信任的循环边界                             | 0      | 0        |      |
| **不安全的数据处理** | TAINTED_SCALAR_ARG_S              | 不可信任的值作为了参数                         | 0      | 0        |      |
| **不安全的数据处理** | FLOAT_NAN_S                       | 可能产生 Nan 和 Inf 的浮点表达式               | 1      | 0        |      |
| **错误表达式**       | BAD_FLOAT_RET                     | 结果不是浮点型                                 | 1      | 0        |      |
| **错误表达式**       | BAD_POINTER_ADDITION              | 错误的指针增量                                 | 0      | 1*   1/  |      |
| **错误表达式**       | ASSERT_EFFECT                     | 断言中的其他作用                               | 0      | 1/       |      |
| **错误表达式**       | PRECEDENCE_ERROR                  | 运算符优先逻辑错误                             | 0      | 0        |      |
| **错误表达式**       | DIVIDE_BY_ZERO_S                  | 除零错误                                       | 0      | 0        |      |
| **错误表达式**       | IA_USEPTRSUBDETSIZE_S             | 使用指针减法确定大小                           | 0      | 0        |      |
| **错误表达式**       | BAD_SHIFT                         | 错误的移位操作                                 | 1      | 2/       |      |
| **错误表达式**       | UNCAUGHT_EXCEPT                   | 未捕获的异常                                   | 0      | 1*       |      |
| **格式化字符串问题** | FORMAT_STRING_S                   | 使用外部控制的格式字符串                       | 0      | 1/       |      |
| **格式化字符串问题** | PRINTF_ARGS                       | Printf 格式说明符的参数中的无效类型            | 0      | 0        |      |
| **格式化字符串问题** | USELESS_PRINTF_FORMAT             | 无效 printf 格式化字符串                       | 0      | 0        |      |
| **格式化字符串问题** | MISSING_PRINTF_ARGS               | 缺少 printf 格式说明符的参数                   | 0      | 0        |      |
| **函数方法使用错误** | VCALL_IN_CTOR_DTOR                | 对虚拟方法的错误调用                           | 0      | 1*       |      |
| **函数方法使用错误** | SWAP_ARG                          | 参数的顺序错误                                 | 0      | 0        |      |
| **函数方法使用错误** | USELESS_CALL_S                    | 无用的调用                                     | 0      | 1/       |      |
| **函数方法使用错误** | SELFCALL_S                        | 禁止使用直接或间接自调用函数                   | 1      | 1/       |      |
| **忽略返回值**       | CHECKED_RETURN_S                  | 来自库函数的未检查返回值                       | 0      | 0        |      |
| **忽略返回值**       | CHECKED_RETURN_BEFORE_S           | 推断来自库函数的未检查返回值                   | 0      | 0        |      |
| **忽略返回值**       | CHECKED_RETURN_BEFORE_SELF_S      | 推断来自用户代码的未检查返回值                 | 0      | 0        |      |
| **缓冲区溢出**       | SPECULATIVE_EXECUTION_DATA_LEAK_S | 推测的执行数据泄露                             | 1      | 0        |      |
| **缓冲区溢出**       | OOB_WRITE_S                       | 越界写入                                       | 0      | 0        |      |
| **缓冲区溢出**       | OOB_READ_S                        | 越界读取                                       | 1      | 0        |      |
| **缓冲区溢出**       | NEGATIVE_INDEX_WRITE_S            | 缓冲区向下溢出写入                             | 1      | 1/       |      |
| **缓冲区溢出**       | NEGATIVE_INDEX_READ_S             | 缓冲区向下溢出读取                             | 0      | 0        |      |
| **缓冲区溢出**       | STACK_OVERFLOW_S                  | 栈写入向上溢出                                 | 1      | 1/       |      |
| **缓冲区溢出**       | HEAP_OVERFLOW_S                   | 堆写入向上溢出                                 | 0      | 3/       |      |
| **缓冲区溢出**       | BAD_READLINK_S                    | 不安全地使用了 Readlink                        | 0      | 1/       |      |
| **缓冲区溢出**       | BAD_ALLOC_STRLEN_S                | 字符串长度计算错误                             | 0      | 0        |      |
| **缓冲区溢出**       | BAD_ALLOC_ARITHMETIC_S            | 离散的指针算术运算                             | 0      | 1/       |      |
| **缓冲区溢出**       | INCOMPATIBLE_CAST_S               | 转型不当导致的越界访问                         | 0      | 1/       |      |
| **缓冲区溢出**       | END_NOT_NULL_S                    | 非 null 缓冲区终止                             | 1      | 1/       |      |
| **缓冲区溢出**       | DEST_TO_SMALL_S                   | 目标缓冲区太小                                 | 1      | 0        |      |
| **缓冲区溢出**       | ARRAY_VS_SINGLETON_S              | 单一对象的指针被错误地当作数组                 | 0      | 0        |      |
| **局部变量未使用**   | UNUSED_VALUE_S                    | 变量赋值未使用                                 | 0      | 1/       |      |
| **局部变量未使用**   | UNUSED_VAR_S                      | 未使用的变量                                   | 0      | 0        |      |
| **局部变量未使用**   | UNUSED_ARG_S                      | 函数参数未使用                                 | 0      | 1/       |      |
| **空指针解引用**     | NPD_NFR_S                         | 函数 NULL 返回值解引用                         | 1      | 0        |      |
| **空指针解引用**     | NPD_COMMON_S                      | 空指针解引用                                   | 0      | 1/       |      |
| **空指针解引用**     | NPD_DYNAMIC_CAST_S                | dynamic_cast 的返回值未检查                    | 1      | 0        |      |
| **空指针解引用**     | NPD_CMP_S                         | 指针被 NULL 检查前或后解引用                   | 0      | 0        |      |
| **控制流错误**       | UNREACHABLE                       | 结构死代码                                     | 0      | 0        |      |
| **控制流错误**       | MISSING_BREAK                     | Switch 中缺少 break                            | 0      | 0        |      |
| **控制流错误**       | DEAD_CODE_S                       | 逻辑死代码                                     | 0      | 1/       |      |
| **控制流错误**       | EVALUATION_ORDER                  | 评估顺序冲突                                   | 0      | 0        |      |
| **内存使用不当**     | OVERLAPPING_COPY_S                | 分配重叠内存                                   | 0      | 0        |      |
| **内存使用不当**     | BAD_FREE_S                        | 释放非堆上的内存                               | 0      | 0        |      |
| **内存使用不当**     | BAD_FILE_OPEN_S                   | 关闭打开失败的文件                             | 0      | 0        |      |
| **内存使用不当**     | MISMATCH_S                        | 不匹配的内存管理例程                           | 0      | 0        |      |
| **内存使用不当**     | WRITE_READ_ONLY_FILE_S            | 尝试对以只读方式打开的流执行写操作             | 0      | 0        |      |
| **内存使用不当**     | DEREF_FILE_S                      | 解引用指向 FILE 对象的指针                     | 0      | 0        |      |
| **内存释放后使用**   | USE_AFTER_FREE_S                  | 释放后使用内存                                 | 0      | 1/       |      |
| **内存释放后使用**   | DOUBLE_FREE_S                     | 双重释放内存                                   | 1      | 0        |      |
| **内存释放后使用**   | RET_STACK_ADDR_S                  | 返回栈变量的地址                               | 1      | 1/       |      |
| **内存释放后使用**   | UMAF_UEXPFILE_S                   | 使用过期的文件描述符                           | 1      | 0        |      |
| **使用未初始化数据** | UNINIT_PTR_S                      | 使用未初始化的指针                             | 1      | 0        |      |
| **使用未初始化数据** | MISSING_RETURN_S                  | 缺少 return 语句                               | 0      | 0        |      |
| **使用未初始化数据** | UNINIT_VAR_S                      | 使用未初始化变量                               | 0      | 0        |      |
| **使用未初始化数据** | UNINIT_IN_CTOR_S                  | 使用未在构造函数中初始化的变量                 | 0      | 1/       |      |
| **无用语句**         | SELF_ASSIGN                       | 自赋值                                         | 0      | 0        |      |
| **无用语句**         | TEST_NOT_ASSIGN                   | 测试应该赋值                                   | 0      | 1/       |      |
| **无用语句**         | CONSTANT_EXPR_RESULT              | 常量表达式结果                                 | 0      | 0        |      |
| **无用语句**         | IDENTICAL_BRANCHES                | 适用于不同分支的相同代码                       | 1      | 0        |      |
| **无用语句**         | ABUSE_COMMA                       | 滥用了逗号运算符                               | 0      | 0        |      |
| **无用语句**         | CONSTANT_EXPR_RESULT_S            | 操作数不影响结果                               | 0      | 0        |      |
| **移植问题**         | POR_PTR_BTW_NPTR_S                | 在不同时是指针或非指针的类型之间进行强制转换   | 0      | 1/       |      |
| **移植问题**         | POR_IMCOMPATIBLE_TYPE_S           | 尝试将表达式强制转换为可能不兼容的大小类型     | 0      | 0        |      |
| **移植问题**         | POR_FTYPE_TO_NFTYPE_S             | 将浮点表达式强制转化为非浮点类型               | 0      | 0        |      |
| **移植问题**         | POR_FPTR_TO_NFPTR_S               | 将指向浮点表达式的指针强制转化为非浮点类型指针 | 0      | 0        |      |
| **整数使用不当**     | SIGN_EXTENSION                    | 非正常的符号扩展                               | 1      | 1/       |      |
| **整数使用不当**     | ENUM_AS_BOOLEAN                   | 滥用了枚举                                     | 0      | 0        |      |
| **整数使用不当**     | MAYBE_MIXED_ENUMS                 | 推断滥用了枚举                                 | 0      | 0        |      |
| **整数使用不当**     | MIXED_ENUMS                       | 混合了枚举类型                                 | 0      | 0        |      |
| **指针问题**         | PTR_FIXXEDADDR_PTR_S              | 将固定地址分配给指针                           | 0      | 1/       |      |
| **指针问题**         | PTR_PROH_PARMPTR_ASSGN_S          | 禁止对参数指针进行赋值                         | 0      | 0        |      |
| **资源泄漏**         | DELETE_ARRAY                      | 对象的非数组删除                               | 0      | 0        |      |
| **资源泄漏**         | VIRTUAL_DTOR                      | 非虚析构函数                                   | 0      | 0        |      |
| **资源泄漏**         | DELETE_VOID                       | 删除了 void 指针                               | 0      | 0        |      |
| **资源泄漏**         | MEMORY_LEAK_S                     | 有效生存期后未释放内存                         | 0      | 0        |      |
| **资源泄漏**         | RESOURCE_LEAK_S                   | 文件使用后未关闭                               | 0      | 1/       |      |
| **资源泄露**         | SINGLE_STREAM_PRE_FILE_S          | 同一文件在不同的流上同时打开                   | 0      | 1*       |      |
| **API 错误**         | CHROOT                            | 不安全的 chroot                                | 0      | 1/       |      |
| **API 错误**         | DANGERFUNC_POTENTIAL_S            | 使用具有潜在危险的函数                         | 0      | 0        |      |
| **API 错误**         | DANGERFUNC_MUST_S                 | 使用危险函数                                   | 0      | 0        |      |
| **API 错误**         | BAD_MEMSET_S                      | Memset 调用错误                                | 0      | 1*       |      |
| **API 错误**         | BAD_COMPARE_MEMCMP_S              | 滥用了 memcmp 风格函数                         | 0      | 0        |      |
| **API 错误**         | BAD_USE_ERRNO_VALUE_S             | 错误使用 errno 值                              | 0      | 0        |      |

#### 结论

1.114 个 SAGA全量模版 规则代码示例文件中， CodeRabbit 

命中 19 个预设缺陷点，命中率16.7%；各个类别的规则都有命中，但命中率都偏低，

2.CodeRabbit 报出的 56个额外正报中 为 6个质量类，48个规范类，2个逻辑语义理解类，由于代码示例文件中除预设缺陷外，其他缺陷偏少，所以可预见的规范类额外正报偏多。

此次CheckerCase测试 规则覆盖率（命中率）偏低的原因可能为底层大模型未涉及到这些具体细分规则模版，如果与其对话进行引导，可以命中，例如：

![image-20260123153609139](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260123153609139.png)

#### 下一步计划

1.测试Benchmark_C_CPP套件 测试其重点规则下，CodeRabbit在被分析程序特征，程序分析能力和应用场景 三方面的分析能力。

2.测试已审计开源项目，测试其真实项目下，跨文件跨模块能力，报出高危漏洞能力。



代码规范类正报：

可能的链接器冲突问题（函数未定义，多重定义）等代码规范问题。

![image-20260123150015689](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260123150015689.png)



![image-20260123150917907](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260123150917907.png)



![image-20260123151047172](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260123151047172.png)



![image-20260123151243007](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260123151243007.png)

### BenchMark_C_CPP测试集

**用于测试Coderabbit审计的程序分析能力。**

CodeSense自研的 C/C++ 基准测试套件，用于静态分析评估，包含 100 多个测试用例，涵盖数据流分析、指针处理、内存管理、约束求解和语言特性，测试CodeRabbit在被分析程序特征，程序分析能力和应用场景 三方面的分析能力。包含了安全和不安全的代码示例，展示了最佳实践和常见漏洞。

详细测试结果：https://github.com/Achillesed/CodeRabbit-Test/pull/6

#### 测试结果

测试时间：14分钟

review结果：30条严重性极高意见，33条主要意见，4条重复意见。

这个 PR 共添加了 **85 个 C/C++ 源文件**：

- 64 个 .c 文件
- 21 个 .cpp 文件

85 个 BenchMark_C_CPP 示例文件中， CodeRabbit 命中 23 个预设缺陷点，命中率27.1%；各个类别的规则都有命中，但命中率都偏低，并且命中率偏低原因不确定，很难感受到能力边界。

| **序号** | **文件名称**                                             | 是否命中            | 额外正报            |
| -------- | -------------------------------------------------------- | ------------------- | ------------------- |
| 1        | **Abilities_Dataflow_Aliasing_2.c**                      |                     |                     |
| 2        | **Abilities_Dataflow_Aliasing_Reference_1.c**            |                     |                     |
| 3        | **Abilities_Dataflow_ConstantProp.c**                    |                     |                     |
| 4        | **Abilites_Env_Std_Move.cpp**                            | 1                   | 1*                  |
| 5        | **Abilites_Env_Std_Vector.cpp**                          | 1                   |                     |
| 6        | **Abilities_Env_MathLib.c**                              |                     | 1*                  |
| 7        | **Abilities_Env_Qt.cpp**                                 |                     |                     |
| 8        | **Abilities_Env_Std_Container.cpp**                      |                     |                     |
| 9        | **Abilities_Env_Std_Span.cpp**                           |                     |                     |
| 10       | **Abilities_Env_Strcpy.c**                               |                     |                     |
| 11       | **Abilities_Env_Teriminator.c**                          |                     |                     |
| 12       | **Abilities_Env_sink_stdlib.c**                          |                     |                     |
| 13       | **Abilities_Env_source_stdlib.c**                        |                     |                     |
| 14       | **Abilities_Env_stdlib_Cond.c**                          | 1*(Cppcheck 2.19.0) | 1*(Cppcheck 2.19.0) |
| 15       | **Abilities_InterProcedural_Param_1a_sideEffect.c**      | 1                   |                     |
| 16       | **Abilities_InterProcedural_Param_1b_sideEffect.c**      |                     |                     |
| 17       | **Abilities_InterProcedural_Param_2a_swap.c**            |                     |                     |
| 18       | **Abilities_InterProcedural_Param_2b_swap.c**            | 1                   |                     |
| 19       | **Abilities_InterProcedural_Param_3.c**                  |                     |                     |
| 20       | **Abilities_InterProcedural_Param_4.c**                  | 1                   |                     |
| 21       | **Abilities_InterProcedural_Regular_1.c**                |                     |                     |
| 22       | **Abilities_InterProcedural_Regular_2.c**                |                     |                     |
| 23       | **Abilities_InterProcedural_Regular_3.c**                | 1                   |                     |
| 24       | **Abilities_InterProcedural_callGraph_1.c**              |                     |                     |
| 25       | **Abilities_InterProcedural_callGraph_2.c**              |                     |                     |
| 26       | **Abilities_InterProcedural_callGraph_3_addition.cpp**   |                     |                     |
| 27       | **Abilities_InterProcedural_callGraph_3_addition.h**     |                     |                     |
| 28       | **Abilities_InterProcedural_callGraph_3_base.h**         |                     |                     |
| 29       | **Abilities_InterProcedural_callGraph_3_division.cpp**   | 1                   |                     |
| 30       | **Abilities_InterProcedural_callGraph_3_division.h**     |                     |                     |
| 31       | **Abilities_InterProcedural_callGraph_3_main.cpp**       | 1                   |                     |
| 32       | **Abilities_InterProcedural_summary_1.c**                |                     |                     |
| 33       | **Other_Crash.cpp**                                      |                     |                     |
| 34       | **Others_ConstraintSolve_SymSym_RelOps.c**               |                     |                     |
| 35       | **Others_ConstraintSolve_UnionInt.c**                    |                     |                     |
| 36       | **Abilities_Sensitivity_Context_Pointer_1.c**            |                     |                     |
| 37       | **Abilities_Sensitivity_Context_Pointer_2.c**            |                     |                     |
| 38       | **Abilities_Sensitivity_Context_Regular.c**              | 1*(Cppcheck 2.19.0) |                     |
| 39       | **Abilities_Sensitivity_Field_ArrayIndex.c**             | 2                   |                     |
| 40       | **Abilities_Sensitivity_Field_Container.cpp**            |                     |                     |
| 41       | **Abilities_Sensitivity_Field_Struct.c**                 | 1*(Cppcheck 2.19.0) |                     |
| 42       | **Abilities_Sensitivity_Flow_1.c**                       |                     |                     |
| 43       | **Abilities_Sensitivity_Flow_Pointer.c**                 |                     |                     |
| 44       | **Abilities_Sensitivity_Flow_Regular.c**                 | 1                   |                     |
| 45       | **Abilities_Sensitivity_Flow_StrongUpdate.c**            |                     |                     |
| 46       | **Abilities_Sensitivity_Object_Regular.cpp**             |                     |                     |
| 47       | **Abilities_Sensitivity_Path_Cond1.c**                   |                     |                     |
| 48       | **Abilities_Sensitivity_Path_Cond2.c**                   |                     |                     |
| 49       | **Abilities_Sensitivity_Path_Loop_01.c**                 |                     |                     |
| 50       | **Abilities_Sensitivity_Path_switch.c**                  | 1                   |                     |
| 51       | **Features_Constraint_Bitwise.c**                        | 1                   |                     |
| 52       | **Features_Constraint_Bitwise_2.c**                      |                     | 2                   |
| 53       | **Features_Constraint_Condition_Expr.c**                 | 1                   |                     |
| 54       | **Features_Constraint_Linear_Arithmetic.c**              | 1*(Cppcheck 2.19.0) |                     |
| 55       | **Features_Constraint_Linear_Cmp.c**                     | 1                   |                     |
| 56       | **Features_Constraint_NonLinear_Arithmetic.c**           |                     | 1                   |
| 57       | **Features_Constraint_NonLinear_Float.c**                | 1                   |                     |
| 58       | **Features_DataType_Array.cpp**                          |                     |                     |
| 59       | **Features_DataType_Array_Cond.c**                       |                     |                     |
| 60       | **Features_DataType_Cast_Cond.c**                        |                     |                     |
| 61       | **Features_DataType_Float_Arithmetic.c**                 |                     |                     |
| 62       | **Features_DataType_Float_Cond.c**                       |                     |                     |
| 63       | **Features_DataType_Global_Array.c**                     |                     |                     |
| 64       | **Features_DataType_Global_Cond1.c**                     | 1                   |                     |
| 65       | **Features_DataType_Global_WithCond.c**                  |                     |                     |
| 66       | **Features_DataType_Global_WithoutCond.c**               |                     |                     |
| 67       | **Features_DataType_Static_WithoutCond.c**               |                     |                     |
| 68       | **Features_Dataflow_Explicit_flows.c**                   |                     |                     |
| 69       | **Features_Dataflow_Implicit_flows.c**                   |                     |                     |
| 70       | **Features_Language_Constructor.h**                      |                     |                     |
| 71       | **Features_Language_Constructor0.cpp**                   |                     |                     |
| 72       | **Features_Language_Constructor1.cpp**                   | 1                   |                     |
| 73       | **Features_Language_FuncPtr.cpp**                        |                     |                     |
| 74       | **Features_Language_Lambda.cpp**                         | 1                   |                     |
| 75       | **Features_Language_Macro.c**                            |                     |                     |
| 76       | **Features_Language_Reference.cpp**                      |                     |                     |
| 77       | **Features_Language_SmartPtr.cpp**                       |                     |                     |
| 78       | **Features_Language_Template.cpp**                       | 1                   |                     |
| 79       | **Features_Language_Ternary.c**                          |                     |                     |
| 80       | **Features_Language_Ternary_Cond1.c**                    |                     |                     |
| 81       | **Features_Language_TryCatch.cpp**                       |                     |                     |
| 82       | **Features_Termination_Loop_Big_Loop.c**                 |                     |                     |
| 83       | **Features_Termination_Loop_Big_Loop_irrelevance.c**     |                     |                     |
| 84       | **Features_Termination_Loop_InfiniteLoop_1.c**           |                     |                     |
| 85       | **Features_Termination_Loop_InfiniteLoop_2.c**           |                     |                     |
| 86       | **Features_Termination_Loop_Range_Based_Loop.cpp**       |                     |                     |
| 87       | **Features_Termination_Recursion.c**                     |                     |                     |
| 88       | **Features_Termination_Recursion_InfiniteRecursion_1.c** |                     |                     |
| 89       | **Features_Termination_Small_Loop_irrelevance.c**        |                     |                     |

#### 覆盖率偏低原因：

与coderabbit对话交流（供参考）

##### 问题1：

![image-20260127142523763](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260127142523763.png)

##### 问题2：

![image-20260127143917546](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260127143917546.png)

##### 问题3：

![image-20260127150621440](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260127150621440.png)

#### 结论：

coderabbit的逻辑似乎并不追求在 Benchmark（基准测试）中拿高分，而是更关注在真实工程里的实用感。但在实际测试中，**让人失望的是，它漏掉了一些非常显而易见的（Low-hanging fruits）缺陷**。像基础的空指针解引用和明显的数组越界这类“送分题”，在默认配置下都没有报出来。这说明它的默认策略为了降低误报可能过于保守，如果想要更高的检出率，必须手动添加自定义审查指令，或者依赖它长时间运行后的智能库积累。

### Clib项目测试

**用于测试Coderabbit对真实项目的审计效果。**

详细测试结果：https://github.com/Achillesed/CodeRabbit-Test/pull/8

先将Clib项目除src目录外提交，再创造一次PR，只有src目录的增量检查，旨在查找src目录中的缺陷。（有Covrity结果进行比对）

#### 测试结果

review结果：1条严重性极高意见，28条主要意见，14条小评论，4条吹毛求疵的评论。

其中命中的关键缺陷：1个/128个

1.RESOURCE_LEAK

![image-20260129144658676](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260129144658676.png)

未命中缺陷包括：CHECK_RETURN、DEADCODE、FORWARD_NULL、NEGETIVE_RETURN、OVERRUN、RESOURCE_LEAK、NEGETIVE_RETURNS、STRING_NULL、STRING_SIZE。

CodeRabbit的1条严重性极高意见：

![image-20260129145727050](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260129145727050.png)

#### 结论:

以Coverity结果作为对比，CodeRabbit报出的缺陷没有固定的模式，随机性大，命中Coverity结果率极低。

## 功能试用

![CodeRabbit架构](https://mintcdn.com/coderabbit/JDF48eE9RUTOwhLY/images/assets/images/architecture.png?fit=max&auto=format&n=JDF48eE9RUTOwhLY&q=85&s=b962fbb736c591ed9f7ba3adfe2cdcb9)

### 1.GitHub PR工作流

详细PR内容：https://github.com/Achillesed/CodeRabbit-Test/pull/1

#### 1.自动生成PR总结

**代码摘要：** CodeRabbit 会对 PR 中的代码变更进行总结，并提供概要说明。这有助于审核人员和产品团队快速了解变更内容及其对产品的影响。

![image-20260120102602664](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260120102602664.png)

#### 2.检查代码

**增量审查：** CodeRabbit 会在每次提交代码后进行全面审查，并向开发者提供增量反馈。它像人工审查员一样，通过对代码进行注释来发现问题并提出改进建议。

潜在问题与修复建议等很合理，让人容易接受。

![image-20260120104330211](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260120104330211.png)

**自定义通用编码规范**：

模式与CDT检测方式类似？

> 使用基于路径的模式或抽象语法树规则添加自定义审查说明。配置 CodeRabbit 以遵循不同文件类型的特定准则并强制执行编码标准。

https://docs.coderabbit.ai/guides/review-instructions

#### 3.对话讨论（AI）

**讨论变更：** CodeRabbit 提供对话功能，允许开发人员和审查人员在变更的上下文中提出问题、生成代码并获得反馈。

![image-20260120150525744](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260120150525744.png)

#### 4.添加注释（自动化工作流）

在GitHub的PR中勾选自动生成注释

📝 Docstrings were successfully generated.

![image-20260120135824455](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260120135824455.png)

#### 5.智能学习（AI）

当您的团队使用 CodeRabbit 时，它会根据聊天互动了解您团队的代码审查偏好，并将这些偏好添加到与您的 Git 平台组织关联的内部数据库中。我们将这些内部记录称为*学习结果*。

![image-20260120150525744](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260120150525744.png)

✏️ 新增学习内容

```
Learnt from: Achillesed
Repo: Achillesed/CodeRabbit-Test PR: 1
File: SAGA_CheckerCase/BAD_MEMSET_S.c:18-21
Timestamp: 2026-01-20T07:01:34.799Z
Learning: For `BAD_MEMSET_S.c` in the `SAGA_CheckerCase` directory: This is a vulnerability demonstration file.When fixing `sizeof(buf)` issues where `buf` is a `char*` parameter, the user may prefer using C++ templates for compile-time array size deduction, but this only works for stack-allocated arrays with known sizes, not for heap-allocated buffers or pointer parameters.
```

### 2.VsCode插件模式

个人GitHub账户申请免费试用14天。

![image-20260117151447687](CodeRabbit%E8%AF%95%E7%94%A8%20&%20%E8%B0%83%E7%A0%94.assets/image-20260117151447687.png)



## 后续研究点

1.代码审查模式以及如何添加自定义审查（路径模式|AST|自主学习）：https://docs.coderabbit.ai/guides/review-instructions

2.类似开源工具（深信服，集Cursor的AI Agent，又有CodeRabbit的AI代码审查）：https://github.com/zgsm-ai/costrict

3.初步以GitHub Webhook + GPT-4o-mini + ast-grep 实现最小的 AI Code Review 系统。

## 参考

1.CodeRabbit官网：https://www.coderabbit.ai/             文档：https://docs.coderabbit.ai/guides/code-review-overview

2.CodeRabbit入门教程及资源官方精选列表：https://github.com/coderabbitai/awesome-coderabbit

3.CodeRabbit官方文档：AI代码审查：https://github.com/coderabbitai/coderabbit-docs



## 相关AI总结生成资料

## CodeRabbit 详细介绍

**CodeRabbit** 是一个创新的 **AI 代码审查工具**，专为开发人员设计，旨在通过自动化代码审查过程，提高代码质量，简化开发工作流，减少手动审查时间，并增强开发人员体验。

它利用先进的机器学习模型（如 **GPT-3.5-turbo** 和 **GPT-4**）对代码进行深度分析，提供精确且可操作的改进建议。CodeRabbit 不仅适用于个人开发者，也是大型企业团队的理想选择。

------

代码审查流程分为多个阶段，如下图所示。当开发者发起拉取请求或向现有拉取请求提交代码时，CodeRabbit 的工作流程就会触发。随后会经历各种总结和审查阶段。

![img](https://framerusercontent.com/images/Y83rpWAtskEjGPenr3dNOUm6mY.png)

### 一、 主要功能

#### 1. 自动化代码审查

- **逐行代码分析**：CodeRabbit 对代码进行逐行分析，识别潜在的问题和最佳实践偏差。
- **问题检测**：能够发现代码中的错误、性能问题、安全性漏洞等。
- **改进建议**：提供具体的改进建议和修正方案，帮助开发人员快速定位并修复问题。

#### 2. 代码优化与重构

- **代码优化**：通过提供优化建议，帮助开发人员提高代码的可读性、可维护性和性能。
- **重构支持**：支持代码重构，帮助开发人员改进代码结构，减少技术债务。

#### 3. 项目管理

- **Pull Request (PR) 审查**：与 GitHub 和 GitLab 无缝集成，支持通过 Webhook 监控 Pull Request 的变化，自动提供审查反馈。
- **变更管理**：帮助团队更好地管理代码变更，提高团队协作效率。

#### 4. 智能学习与个性化

- **智能学习**：CodeRabbit 具备智能学习能力，能从用户的使用中学习并微调其评论，确保编码偏好越来越一致。
- **个性化设置**：用户可以根据需要调整审查过程的重点或目标，实现个性化的代码审查体验。

#### 5. 对话式交互

- **编码助手聊天机器人**：提供智能聊天助手功能，允许开发人员与 AI 进行对话，解答问题或生成代码。
- **上下文感知反馈**：提供基于代码上下文的审查反馈，帮助开发人员更好地理解代码变更的意图和影响。

------

### 二、 优势特点

- **高效性**：自动化代码审查显著减少了手动审查的时间和工作量，使开发人员能够更专注于编写和测试代码。
- **准确性**：采用先进的机器学习模型，能够精确地识别代码中的问题，并提供具体、可操作的改进建议。
- **灵活性**：支持多种代码审查方式，包括实时审查、增量审查等，满足不同项目的需求。
- **集成性**：与 GitHub 和 GitLab 无缝集成，支持通过 Webhook 监控 Pull Request 的变化，方便团队协作。
- **智能性**：具备智能学习能力，能从用户的使用中学习并优化审查效果，提供更个性化的审查体验。

------

### 三、 应用场景

- **个人开发者**：帮助个人开发者提高代码质量，减少手动审查时间，提高开发效率。
- **开源项目**：为开源项目提供免费的专业代码审查服务，帮助维护者快速发现代码中的问题。
- **企业级团队**：支持大型开发团队进行高效的代码审查和管理，提高团队协作效率，确保代码质量。

------

### 四、 使用流程

1. **注册与登录**：访问 CodeRabbit 官方网站，创建账户并登录。
2. **集成设置**：将 CodeRabbit 集成到代码审查流程中，通常涉及与 GitHub 或 GitLab 的集成设置。
3. **开始审查**：提交 Pull Request 后，CodeRabbit 将自动开始审查过程，提供逐行代码的审查反馈。
4. **查看与建议**：开发人员可以在 CodeRabbit 的界面中查看审查反馈，并根据建议进行代码修改。
5. **持续优化**：随着时间的推移，CodeRabbit 将从用户的使用中学习并优化审查效果，提供更准确和个性化的建议。



## 技术实现

### 一、 智能编排与模型路由层 (The AI Orchestration)

这是 CodeRabbit 的“大脑”，通过多模型协同解决成本、速度与逻辑深度的矛盾。

- **多模型路由策略 (Multi-model Routing)：**
  - **轻量级模型 (如 GPT-4o-mini / Llama 3)：** 负责生成 PR 摘要、技术简述及初步噪声过滤，确保极速响应。
  - **高性能模型 (如 GPT-4o / Claude 3.5 Sonnet)：** 介入深度逻辑审查、安全漏洞发现和跨文件架构建议。
- **上下文压缩与 RAG 增强：** 针对 LLM 的 Token 限制，开发了“摘要提取 -> 关键片段过滤 -> 优先级排序”算法。仅将最相关的代码片段输入模型，确保超大型 PR 也能在窗口内完成处理。
- **结构化 Prompt 工程：** 弃用标准的 `git diff` 格式，采用自研的输入结构，利用 **Few-shot Learning** 引导模型稳定输出 JSON 格式的审查建议，便于系统自动回写评论。

### 二、 代码图谱与上下文深度分析 (Contextual Intelligence)

CodeRabbit 能够像“资深架构师”一样思考，得益于其对代码库全局关系的理解。

- **代码图谱 (Code Graph)：** 基于 **Neo4j** 等图数据库构建全量代码符号索引。当某处函数被修改时，AI 能通过图谱溯源，识别出所有受影响的下游模块及跨文件依赖。
- **混合分析引擎：**
  - **静态分析 (SAST)：** 集成 **ast-grep**、**Tree-sitter** 等工具解析抽象语法树 (AST)，精准识别代码异味 (Code Smell)。
  - **工业级 Linter 集成：** 同时调用 ESLint、SonarQube 等 40 多个传统工具进行多维度扫描，作为 AI 逻辑审查的补充。
- **增量分析算法：** 算法能够精确识别本次 Commit 的代码变更及其直接辐射范围，避免对未变动部分产生重复或无效的评论。

### 三、 自动化验证与安全沙盒 (The Validation Sandbox)

为了确保 AI 建议的“一键修复”是真正可运行的，CodeRabbit 引入了闭环验证机制。

- **隔离沙盒环境 (Ephemeral Environments)：** 使用 **Firecracker**、**gVisor** 或 **Docker** 构建轻量化容器。在完全隔离的“Jail Tool”中执行 AI 建议的代码，运行编译和单元测试。
- **代理验证 (Agentic Verification)：** AI Agent 在沙盒中尝试修复 Bug 并观察测试反馈。如果测试失败，Agent 会自我迭代修复方案，直到生成真正可运行的代码补丁。
- **动态分析：** 在沙盒运行中捕获死锁、竞态条件等静态分析无法发现的运行时缺陷。

### 四、 平台集成与工程化流转 (Workflow & Fullstack)

无缝嵌入开发者的日常工作流，降低工具的使用阻力。

- **GitOps 深度集成：** 利用 GitHub Apps/GitLab API 监听 Webhook 事件。支持 **Markdown 渲染引擎**（含代码高亮、Mermaid.js 架构图），将复杂的变更逻辑可视化。
- **全栈工具链：**
  - **IDE 插件：** 开发 VSCode 扩展，在本地开发阶段（提交前）介入，提供实时预审。
  - **CLI 工具：** 使用 Go 或 Node.js 开发命令行工具，支持在本地终端与 AI 审查助手交互。
- **可视化引擎：** 自动将 PR 中的逻辑变更转化为 **Mermaid 流程图**，帮助审查者一秒读懂系统改动。

### 五、 隐私安全与自主学习系统 (Security & Learning)

- **数据隐私基座：** 采用**临时数据处理 (In-memory Processing)**。坚持“无状态”设计，所有审查状态存储在 PR 评论元数据中；严格遵守 SOC2/GDPR，代码不持久化存储，不用于模型训练。
- **自主学习系统 (Learning Base)：** 基于 **Pinecone/Milvus** 等向量数据库，存储团队对 AI 评论的反馈（如“点击忽略”）。AI 会从中学习团队的特定编码偏好（如缩进、变量命名习惯），实现越用越精准。

------

### 技术架构总结表

| **核心维度**   | **关键实现技术**                  | **解决的核心问题**                   |
| -------------- | --------------------------------- | ------------------------------------ |
| **大脑逻辑**   | GPT-4o / Claude 3.5 / 多模型路由  | 平衡推理深度、响应速度与 API 成本    |
| **上下文感知** | Neo4j (图谱) / RAG / AST-grep     | 解决跨文件依赖分析，防止 AI 幻觉     |
| **质量基石**   | 40+ 工业级 Linters / 静态分析     | 保证基础语法正确与编码规范统一       |
| **闭环验证**   | Firecracker 沙盒 / Agentic 测试   | 确保 AI 建议的可运行性，防范代码注入 |
| **交互体验**   | GitHub API / Mermaid.js / VSCode  | 极低摩擦地嵌入现有 CI/CD 工作流      |
| **数据安全**   | 内存处理 / 无状态设计 / SOC2 规范 | 消除企业对代码资产外泄与训练的顾虑   |



## 是否有用？

在 2026 年的今天，AI 辅助编程已经从“写代码”进化到了“保质量”的阶段。CodeRabbit 作为目前市占率极高的 AI 代码审查（Code Review）工具，到底值不值得你掏钱或花精力去集成？

以下是基于 2026 年最新行业评测和用户反馈的非技术性深度评估：

### 1. CodeRabbit 好不好？

**好，它是目前市场上最像“人类资深架构师”的 AI 审查工具，但它更像是一个“永不疲倦的质检员”而非“决策者”。** 它不再只是检查分号或命名规范，而是能理解你的代码逻辑、上下文，甚至能指出潜在的业务逻辑漏洞。

------

### 2. 核心价值：为什么要用它？

它的核心价值不在于替代人类，而在于**“消除低级错误”**和**“缩短等待时间”**：

- **解放资深工程师：** 以前高级开发要花 30 分钟纠正新人的并发风险或资源泄漏，现在 CodeRabbit 在 PR（拉取请求）提交后的 1 分钟内就能指出来。
- **心理安全感：** 对于开发者来说，在同事看到代码前，先让 AI 把“愚蠢的错误”挑出来，能极大缓解 Review 时的压力。

------

### 3. 优缺点深度拆解

| **维度**     | **优点 (Pros)**                                              | **缺点 (Cons)**                                              |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **智能程度** | **上下文感知力极强。** 它能理解不同文件之间的调用关系，甚至能读懂你的需求文档（PRD），检查代码是否偏离了业务目标。 | **依然存在“幻觉”。** 偶尔会一本正经地建议你使用一个不存在的库函数，或者过度解读一段简单的代码。 |
| **交互体验** | **对话式修复。** 你可以直接在 GitHub/GitLab 评论区回怼它：“这里我是为了性能故意这么写的”，它会理解并闭嘴，或者根据你的反馈更新建议。 | **噪音问题。** 如果配置不当，它会像个碎碎念的老师，对每一行无关紧要的格式都发评论，让人心烦。 |
| **学习能力** | **越用越聪明。** 它能学习团队的特定编码风格和禁忌，你点一次“拒绝建议”，它下次就会减少此类反馈。 | **配置门槛。** 要想让它真正懂你们团队的“土话”和私有架构，需要花时间调整配置和自定义规则。 |
| **效率提升** | **自动生成摘要。** 自动帮你写 PR 的 Release Note 和改动说明，这能节省大量写文档的时间。 | **成本压力。** 它是按活跃贡献者收费的，对于大型外包团队或人员流动大的公司，成本并不低。 |

------

### 4. 适用人群：谁该买，谁该绕道？

- **强烈推荐：**
  - **快速扩张的初创团队：** 老人不够用，新人代码质量参差不齐。
  - **开源项目维护者：** CodeRabbit 对开源免费，且能处理海量的低质量 PR 筛选。
  - **追求极致质量的金融/安全团队：** 需要多一层 AI 审计来防止低级逻辑漏洞。
- **不建议使用：**
  - **个人开发者的小项目：** 自己写自己看，Copilot 本身的建议就够了。
  - **对隐私极度敏感且无法使用云端 AI 的团队：** 尽管它有私有化方案，但部署和维护成本极高。

------

### 5. 测试结果如何佐证其价值？

- **PR 周期缩短：** 数据显示，使用 CodeRabbit 后，PR 从提交到合并的时间（Cycle Time）平均缩短了 **40% - 50%**。因为它完成了“第一轮 Review”。
- **Bug 捕获率：** 在针对已知漏洞（Bug Injection）的盲测中，CodeRabbit 捕获了 **82%**（通常会低于） 的逻辑缺陷和安全隐患，高于同类竞品的平均水平（约 70%）。
- **代码接受率（Acceptance Rate）：** 在调优良好的团队中，开发者对 CodeRabbit 建议的采纳率通常在 **60% 以上**。如果低于 30%，说明你的配置有问题或者团队代码已经非常完美了。
- **漏网之鱼：** 统计发现，强制合并（Forced Merge）导致的线上事故率下降了 **60%**，因为 AI 强制执行了更严格的检查流程。