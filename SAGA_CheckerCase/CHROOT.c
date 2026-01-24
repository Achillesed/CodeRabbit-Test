/**
    Filename: CHROOT.c
    Vuln: CHROOT
    SourceLine: -1
    SinkLine: 19
    Comment: 不安全的 chroot
*/

#include <stdio.h>
#include <stdlib.h>

char * read_from_network();
int chroot( char *);
int open (char * path, int mode);
int chdir(char *);

void CHROOT_BAD(int *fd)
{
    char *filename;
    chroot("/var/ftp/pub"); //缺陷点：缺少调用 chdir 方法的代码
    filename = read_from_network();
    *fd = open(filename, 0);
}

void CHROOT_GOOD(int *fd)
{
    char *filename;
    chroot("/var/ftp/pub");
    chdir("/");      //修复点：调用 chdir 方法
    filename = read_from_network();
    *fd = open(filename, 0);
}