/*
 * Comment
 */
#include <stdio.h>

#define FT(code) int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, #code"\nFT("#code")"); fclose(fp); return 0; }
FT(#define FT(code) int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, #code"\nFT("#code")"); fclose(fp); return 0; })