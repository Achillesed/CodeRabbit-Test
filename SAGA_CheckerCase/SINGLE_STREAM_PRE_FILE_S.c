#include <stdio.h>

/**
 * Demonstrates opening the same file twice without closing the first stream.
 *
 * Opens "tmp.txt" with mode "r+", then opens "tmp.txt" again with mode "r"
 * before closing the first FILE pointer, and finally closes both streams.
 *
 * @note Opening a second stream to the same file before closing the first
 *       may lead to undefined or unsafe behavior on some platforms.
 */
void SINGLE_STREAM_PRE_FILE_S_BAD(void) {
    FILE *fw = fopen("tmp.txt", "r+");
    FILE *fr = fopen("tmp.txt", "r");   //违规
    fclose(fw);
    fclose(fr);
}

/**
 * Open and close "tmp.txt" with update mode, then reopen it for read-only access.
 *
 * Opens "tmp.txt" using mode "r+", closes that stream, then opens "tmp.txt" using mode "r"
 * and closes that stream, ensuring the first FILE* is closed before the file is reopened.
 */
void SINGLE_STREAM_PRE_FILE_S_GOOD(void) {
    FILE *fw = fopen("tmp.txt", "r+");
    fclose(fw);
    FILE *fr = fopen("tmp.txt", "r");   //不违规
    fclose(fr);
}