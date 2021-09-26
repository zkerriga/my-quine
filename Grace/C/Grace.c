/*
 * Comment
 */
#include <stdio.h>
#define TOP "/*\n * Comment\n */\n#include <stdio.h>\n"
#define FT(code) int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, TOP"#define TOP test\n"#code"\nFT("#code")"); fclose(fp); return 0; }
FT(#define FT(code) int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, TOP"#define TOP test\n"#code"\nFT("#code")"); fclose(fp); return 0; })