#include <stdio.h>
#define TOP "#include <stdio.h>\n"
#define FT(code) const char * f() { return "\"#include <stdio.h>\\n\""; } int main() { FILE *fp = fopen("Sully_N.c", "w"); fprintf(fp, "%s#define TOP %s\n%s\nFT(%s)\n", TOP, f(), #code, #code); fclose(fp); return 0; }
FT(#define FT(code) const char * f() { return "\"#include <stdio.h>\\n\""; } int main() { FILE *fp = fopen("Sully_N.c", "w"); fprintf(fp, "%s#define TOP %s\n%s\nFT(%s)\n", TOP, f(), #code, #code); fclose(fp); return 0; })
