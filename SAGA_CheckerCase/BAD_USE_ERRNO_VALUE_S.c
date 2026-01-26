/**
    Filename: BAD_USE_ERRNO_VALUE_S.c
    Vuln: BAD_USE_ERRNO_VALUE_S
    SourceLine: -1
    SinkLine: 14,17
    Comment: 错误使用 errno 值
*/

#include <stdlib.h>
#include <errno.h>

/**
 * Show incorrect handling of errno around numeric conversions.
 *
 * This function performs two string-to-double conversions while misusing `errno`:
 * it does not clear `errno` before the first `strtod` call, resets `errno`
 * after that call (invalidating any error indication), then relies on `errno`
 * after calling `atof`, which may not set `errno`. The function is intended
 * to illustrate a faulty errno usage pattern.
 *
 * @param p NUL-terminated string containing the numeric value to convert.
 */
void BAD_USE_ERRNO_VALUE_S_BAD(const char* p)
{
    double d = strtod(p, NULL); // 违规 - 在调用 "strtod" 之前应将 errno 设置为0,并在调用后进行检查
    errno = 0;
    d = atof(p);
    if (0 != errno) { // 违规 - "atof" 可能会或者也可能不会设置 errno
        // Handle error...
    }
}

/**
 * Demonstrates correct errno initialization and error checking for a `strtod` conversion,
 * then performs a subsequent `atof` conversion without additional errno handling.
 *
 * @param p Input C string containing the numeric representation to convert.
 */
void BAD_USE_ERRNO_VALUE_S_GOOD(const char* p)
{
    errno = 0;
    double d = strtod(p, NULL);
    if (0 != errno) {
        // 处理错误...
    }
    d = atof(p);
}