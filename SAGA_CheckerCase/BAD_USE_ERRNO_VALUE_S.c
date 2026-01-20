/**
    Filename: BAD_USE_ERRNO_VALUE_S.c
    Vuln: BAD_USE_ERRNO_VALUE_S
    SourceLine: -1
    SinkLine: 14,17
    Comment: 错误使用 errno 值
*/

#include <stdlib.h>
#include <errno.h>

void BAD_USE_ERRNO_VALUE_S_BAD(const char* p)
{
    double d = strtod(p, NULL); // 违规 - 在调用 "strtod" 之前应将 errno 设置为0,并在调用后进行检查
    errno = 0;
    d = atof(p);
    if (0 != errno) { // 违规 - "atof" 可能会或者也可能不会设置 errno
        // Handle error...
    }
}

void BAD_USE_ERRNO_VALUE_S_GOOD(const char* p)
{
    errno = 0;
    double d = strtod(p, NULL);
    if (0 != errno) {
        // 处理错误...
    }
    d = atof(p);
}