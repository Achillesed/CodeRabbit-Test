/**
    Filename: SIGN_EXTENSION.c
    Vuln: SIGN_EXTENSION
    SourceLine: -1
    SinkLine: 12
    Comment: 非正常的符号扩展
*/

unsigned long SIGN_EXTENSION_BAD(unsigned char *p)
{
    return  p[0] |
           (p[1] << 8) |
           (p[2] << 16) |
           (p[3] << 24);
}

unsigned long SIGN_EXTENSION_GOOD(unsigned char *p)
{
    return (unsigned int) (p[0] |
           (p[1] << 8) |
           (p[2] << 16) |
           (p[3] << 24));
}