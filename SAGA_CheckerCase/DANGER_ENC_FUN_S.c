/**
    Filename: DANGER_ENC_FUN_S.c
    Vuln: DANGER_ENC_FUN_S
    SourceLine: -1
    SinkLine: 16
    Comment: 使用已破解或危险的加密算法
*/

#include <openssl/sha.h>
#include <openssl/md5.h>
#define MD5_DIGEST_LENGTH 16

void DANGER_ENC_FUN_S_BAD(const unsigned char *msg, size_t len) 
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    MD5(msg, len, md5digest);
}

void DANGER_ENC_FUN_S_GOOD(const unsigned char *msg, size_t len) 
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    SHA256(msg, len, md5digest);
}