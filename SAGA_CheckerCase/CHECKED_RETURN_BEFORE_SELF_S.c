/**
    Filename: CHECKED_RETURN_BEFORE_SELF_S.c
    Vuln: CHECKED_RETURN_BEFORE_SELF_S
    SourceLine: -1
    SinkLine: 54
    Comment: 推断来自用户代码的未检查返回值
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * Read up to `size` bytes from the file descriptor `fd` into `buffer`.
 *
 * @param fd File descriptor to read from.
 * @param buffer Pointer to the destination buffer where read bytes will be stored.
 * @param size Maximum number of bytes to read into `buffer`.
 * @returns Number of bytes read on success, or -1 on error.
 */
ssize_t custom_read(int fd, void *buffer, size_t size) {
    ssize_t bytes_read;
    bytes_read = read(fd, buffer, size);
    if (bytes_read == -1) {
        perror("custom_read: read");
        return -1; // 返回 -1 表示发生错误
    }
    return bytes_read; // 返回成功读取的字节数
}
/**
 * Perform four sequential reads from the given file descriptor, verifying each read's result.
 *
 * @param fd File descriptor to read from.
 * @returns `-1` if any read returns an error, `1` if all reads complete successfully.
 */
int HAS_CHECKED_RETURN_BEFORE(int fd) {
    char buf[10];
    int bytes_read = custom_read(fd, buf, 10); // 检查点1
    if(bytes_read == -1)
    {
        return -1;
    }
    /* do something */
    char buf2[10];
    int bytes_read2 = custom_read(fd, buf2, 10); // 检查点2
    if(bytes_read2 == -1)
    {
        return -1;
    }
    /* do something */
    char buf3[10];
    int bytes_read3 = custom_read(fd, buf3, 10); // 检查点3
    if(bytes_read3 == -1)
    {
        return -1;
    }
    /* do something */
    char buf4[10];
    int bytes_read4 = custom_read(fd, buf4, 10); // 检查点4
    if(bytes_read4 == -1)
    {
        return -1;
    }
    /* do something */
    return 1;
}
/**
 * Performs a read from the given file descriptor into a 10-byte stack buffer without checking the read result.
 *
 * @param fd File descriptor to read from.
 * @returns 1 indicating the function completed (the read result is intentionally ignored).
 */
int CHECKED_RETURN_BEFORE_S_BAD(int fd) {
    char buf[10];
    custom_read(fd, buf, 10); // 缺陷点：未检查点，且满足默认条件（检查/检查+未检查 >= 0.8）
    /* do something */
    return 1;
}

/**
 * Reads up to 10 bytes from the given file descriptor into an internal buffer and returns a status code.
 *
 * If the underlying read fails, the function propagates the error; otherwise it indicates success.
 *
 * @return `-1` if the read failed, `1` on success.
 */
int CHECKED_RETURN_BEFORE_S_GOOD(int fd) {
    char buf[10];
    if(custom_read(fd, buf, 10) == -1) // 修复点：检查点
    {
        return -1;
    }
    /* do something */
    return 1;
}