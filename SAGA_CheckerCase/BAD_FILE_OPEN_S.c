/**
    Filename: BAD_FILE_OPEN_S.c
    Vuln: BAD_FILE_OPEN_S
    SourceLine: -1
    SinkLine: 17
    Comment: 关闭打开失败的文件
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Demonstrates opening "/proc/stat" and unconditionally closing the FILE pointer.
 *
 * Opens "/proc/stat" for reading and then calls fclose without checking whether fopen succeeded; if fopen returns NULL, calling fclose on a NULL pointer leads to undefined behavior.
 */
void BAD_FILE_OPEN_S_BAD()
{
  FILE *fd;
  fd = fopen("/proc/stat", "r");
   /* do something */
  fclose(fd);       //缺陷点：关闭的文件符 fd 可能打开失败
}

/**
 * Open "/proc/stat" for reading, perform processing if opened, and close the file.
 *
 * Attempts to open "/proc/stat"; if the open fails the function returns immediately.
 * If the file is opened successfully, performs processing (placeholder) and then closes the file.
 */
void BAD_FILE_OPEN_S_GOOD()
{
  FILE *fd;
  fd = fopen("/proc/stat", "r");
  if(fd == NULL) return;
   /* do something */
  fclose(fd);      //修复点：关闭前检查了 fopen 返回值，防止打开失败
}