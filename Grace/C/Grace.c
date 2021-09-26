/*
 * Comment
 */
#include <stdio.h>
#define TOP "/*\n * Comment\n */\n#include <stdio.h>\n"
#define FT(code) int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, "%s#define TOP %s\n%s\nFT(%s)", TOP, "test", #code, #code); fclose(fp); return 0; }
FT(#define FT(code) int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, "%s#define TOP %s\n%s\nFT(%s)", TOP, "test", #code, #code); fclose(fp); return 0; })