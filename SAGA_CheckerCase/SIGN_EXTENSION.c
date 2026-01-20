/**
 * Combine four consecutive bytes into a 32-bit value (little-endian).
 *
 * Interprets p[0]..p[3] as bytes from least-significant to most-significant and composes a 32-bit value.
 *
 * @param p Pointer to at least four bytes to read.
 * @returns 32-bit value with p[0] as least-significant byte and p[3] as most-significant byte, returned as unsigned long.
 */

unsigned long SIGN_EXTENSION_BAD(unsigned char *p)
{
    return  p[0] |
           (p[1] << 8) |
           (p[2] << 16) |
           (p[3] << 24);
}

/**
 * Combine four bytes from a buffer into a 32-bit unsigned value using little-endian byte order.
 *
 * @param p Pointer to a buffer with at least four bytes; p[0] is the least-significant byte and p[3] is the most-significant byte.
 * @returns The 32-bit unsigned value formed by concatenating p[0]..p[3] (little-endian).
 */
unsigned long SIGN_EXTENSION_GOOD(unsigned char *p)
{
    return (unsigned int) (p[0] |
           (p[1] << 8) |
           (p[2] << 16) |
           (p[3] << 24));
}