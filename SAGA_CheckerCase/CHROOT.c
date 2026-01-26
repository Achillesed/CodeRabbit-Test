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

/**
 * Change the process root to /var/ftp/pub, read a filename from the network, and open that file.
 *
 * This function calls chroot("/var/ftp/pub"), obtains a filename via read_from_network(), and stores
 * the resulting file descriptor from open(filename, 0) into *fd. It does not call chdir(), so the
 * process's current working directory is not adjusted after the chroot call.
 *
 * @param fd Pointer to an int where the opened file descriptor will be stored.
 */
void CHROOT_BAD(int *fd)
{
    char *filename;
    chroot("/var/ftp/pub"); //缺陷点：缺少调用 chdir 方法的代码
    filename = read_from_network();
    *fd = open(filename, 0);
}

/**
 * Change root to /var/ftp/pub, ensure the working directory is set inside the new root, read a filename from the network, and open that file.
 * Reads a pathname from the network, opens it, and stores the resulting file descriptor through `fd`.
 * @param fd Pointer to an integer where the opened file descriptor will be stored.
 */
void CHROOT_GOOD(int *fd)
{
    char *filename;
    chroot("/var/ftp/pub");
    chdir("/");      //修复点：调用 chdir 方法
    filename = read_from_network();
    *fd = open(filename, 0);
}