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

/**
 * Compute the MD5 digest of the provided message and discard the result.
 *
 * This function computes the MD5 hash of `msg` (length `len`) into a local buffer
 * and does not expose, return, or persist the digest. MD5 is cryptographically
 * broken and should not be used for security-sensitive purposes.
 *
 * @param msg Pointer to the input message bytes to hash.
 * @param len Length of the input message in bytes.
 */
void DANGER_ENC_FUN_S_BAD(const unsigned char *msg, size_t len) 
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    MD5(msg, len, md5digest);
}

/**
 * Compute the SHA-256 digest of the provided message; the digest is generated locally and not returned.
 *
 * @param msg Pointer to the input message buffer.
 * @param len Length of the input message in bytes.
 */
void DANGER_ENC_FUN_S_GOOD(const unsigned char *msg, size_t len) 
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    SHA256(msg, len, md5digest);
}