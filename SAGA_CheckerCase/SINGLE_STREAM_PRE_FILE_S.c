#include <stdio.h>

void SINGLE_STREAM_PRE_FILE_S_BAD(void) {
    FILE *fw = fopen("tmp.txt", "r+");
    FILE *fr = fopen("tmp.txt", "r");   //违规
    fclose(fw);
    fclose(fr);
}

void SINGLE_STREAM_PRE_FILE_S_GOOD(void) {
    FILE *fw = fopen("tmp.txt", "r+");
    fclose(fw);
    FILE *fr = fopen("tmp.txt", "r");   //不违规
    fclose(fr);
}
