int i = 5;
#include <stdio.h>
#define TOP "#include <stdio.h>\n"
//#define FT(code) char first_str[100]; const char * get_first_str() { sprintf(first_str, "int i = %d;\n", i - 1); return first_str; } const char * top() { return "\"#include <stdio.h>\\n\""; } int main() { char filename[100]; if (i > 0) { sprintf(filename, "Sully_%d.c", i - 1); FILE *fp = fopen(filename, "w"); fprintf(fp, "%s%s#define TOP %s\n%s\nFT(%s)\n", get_first_str(), TOP, top(), #code, #code); fclose(fp); } return 0; }
//FT(#define FT(code) char first_str[100]; const char * get_first_str() { sprintf(first_str, "int i = %d;\n", i - 1); return first_str; } const char * top() { return "\"#include <stdio.h>\\n\""; } int main() { char filename[100]; if (i > 0) { sprintf(filename, "Sully_%d.c", i - 1); FILE *fp = fopen(filename, "w"); fprintf(fp, "%s%s#define TOP %s\n%s\nFT(%s)\n", get_first_str(), TOP, top(), #code, #code); fclose(fp); } return 0; })


char first_str[100];
const char * get_first_str() {
	sprintf(first_str, "int i = %d;\n", i - 1);
	return first_str;
}

const char * top() { return "\"#include <stdio.h>\\n\""; }

int fmain(const char * code) {
	char filename[100];
	if (i > 0) {
		sprintf(filename, "Sully_%d.c", i - 1);
		FILE *fp = fopen(filename, "w");
		fprintf(fp, "%s%s#define TOP %s\n%s\nFT(%s)\n", get_first_str(), TOP, top(), code, code);
		fclose(fp);
	}
	return 0;
}

int main() {
	return fmain("code");
}
