#！/usr/bin/bash
build-bom generate-bitcode --clang /home/wei/Downloads/llvm-project-llvmorg-15.0.6/build/bin/clang --remove-argument=O2 --remove-argument=O3 --inject-argument=-O0 --inject-argument=-Xclang --inject-argument=-no-opaque-pointers --inject-argument=-fno-discard-value-names -- make -j10 --trace
