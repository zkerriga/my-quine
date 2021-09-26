/*
 * Comment
 */
#include <stdio.h>
#define TOP "/*\n * Comment\n */\n#include <stdio.h>\n"
#define FT(code) const char * f() { return "\"/*\\n * Comment\\n */\\n#include <stdio.h>\\n\""; } int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, "%s#define TOP %s\n%s\nFT(%s)\n", TOP, f(), #code, #code); fclose(fp); return 0; }
FT(#define FT(code) const char * f() { return "\"/*\\n * Comment\\n */\\n#include <stdio.h>\\n\""; } int main() { FILE *fp = fopen("Grace_kid.c", "w"); fprintf(fp, "%s#define TOP %s\n%s\nFT(%s)\n", TOP, f(), #code, #code); fclose(fp); return 0; })
