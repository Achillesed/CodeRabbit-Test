/**
    Filename: CHECKED_RETURN_BEFORE_S.c
    Vuln: CHECKED_RETURN_BEFORE_S
    SourceLine: -1
    SinkLine: 41
    Comment: 推断来自库函数的未检查返回值
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int checkFunc(int fd) {
    char buf[10];
    int x = read(fd, buf, 10); // 检查点1
    if(x == -1)
    {
        return -1;
    }
    char buf2[10];
    int x2 = read(fd, buf2, 10); // 检查点2
    if(x2 == -1)
    {
        return -1;
    }
    char buf3[10];
    int x3 = read(fd, buf3, 10); // 检查点3
    if(x3 == -1)
    {
        return -1;
    }
    char buf4[10];
    int x4 = read(fd, buf4, 10); // 检查点4
    if(x4 == -1)
    {
        return -1;
    }
    return 1;
}
int CHECKED_RETURN_BEFORE_S_BAD(int fd) {
    char buf[10];
    read(fd, buf, 10); // 缺陷点：未检查点，且满足默认条件（检查/检查+未检查 >= 0.8）
    /* do something */
    return 1;
}

int CHECKED_RETURN_BEFORE_S_GOOD(int fd) {
    char buf[10];
    if(read(fd, buf, 10) == -1) // 修复点：检查点
    {
        return -1;
    }
    /* do something */
    return 0;
}