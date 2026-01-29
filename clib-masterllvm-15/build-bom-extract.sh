#! /usr/bin/bash
if [ $# -ne 1 ];
then
	echo "The number of parameters is not correct!"
	exit -1
fi

exe_file_name=${1}
bitcode_file_name=${exe_file_name}.bc
build-bom extract-bitcode --llvm-link-path /home/wei/Downloads/llvm-project-llvmorg-15.0.6/build/bin/llvm-link ${exe_file_name} -o ${bitcode_file_name}
