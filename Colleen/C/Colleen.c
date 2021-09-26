#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define PROGRAM_MAXIMUM_SIZE 10240

typedef char *          buffered_string;
typedef const char *    const_string;

buffered_string write_source_code_to_buffer(buffered_string output_buffer);
const_string    get_other_source_code();

#define DOUBLE_QUOTE '"'
#define ENTER '\n'
#define SLASH '\\'
#define N_SYMBOL 'n'

void fill_codify_lines(buffered_string destination, const_string lines) {
    if (*lines == 0) {
        return;
    }
    else if (*lines == ENTER) {
        *destination++ = SLASH;
        *destination++ = N_SYMBOL;
        *destination++ = DOUBLE_QUOTE;
        *destination++ = ENTER;
        if (lines[1] != 0)
            *destination++ = DOUBLE_QUOTE;
        fill_codify_lines(destination, lines + 1);
    }
    else if (*lines == SLASH) {
        *destination++ = SLASH;
        *destination++ = SLASH;
        fill_codify_lines(destination, lines + 1);
    }
    else if (*lines == DOUBLE_QUOTE) {
        *destination++ = SLASH;
        *destination++ = DOUBLE_QUOTE;
        fill_codify_lines(destination, lines + 1);
    }
    else {
        *destination++ = *lines;
        fill_codify_lines(destination, lines + 1);
    }
}

/*
 * We need to format the lines of code
 */
buffered_string codify_lines(buffered_string buffer, const_string source_code_lines) {
    *buffer = DOUBLE_QUOTE;
    fill_codify_lines(buffer + 1, source_code_lines);
    return buffer;
}

int main() {
    char printing_buffer[PROGRAM_MAXIMUM_SIZE];
    bzero(printing_buffer, PROGRAM_MAXIMUM_SIZE);
    /*
     * Here we print the source code of the program
     */
    const_string full_source_code = write_source_code_to_buffer(printing_buffer);
    write(1, full_source_code, strlen(full_source_code));
    return 0;
}

buffered_string write_source_code_to_buffer(buffered_string output_buffer) {
    char buffer[PROGRAM_MAXIMUM_SIZE];
    bzero(buffer, PROGRAM_MAXIMUM_SIZE);
    const_string other_source_code = get_other_source_code();

    sprintf(output_buffer,
"%s"
"const_string get_other_source_code() {\n"
"    return\n"
"%s"
";}\n",
other_source_code, codify_lines(buffer, other_source_code));
    return output_buffer;
}

const_string get_other_source_code() {
    return
"#include <string.h>\n"
"#include <unistd.h>\n"
"#include <stdio.h>\n"
"\n"
"#define PROGRAM_MAXIMUM_SIZE 10240\n"
"\n"
"typedef char *          buffered_string;\n"
"typedef const char *    const_string;\n"
"\n"
"buffered_string write_source_code_to_buffer(buffered_string output_buffer);\n"
"const_string    get_other_source_code();\n"
"\n"
"#define DOUBLE_QUOTE '\"'\n"
"#define ENTER '\\n'\n"
"#define SLASH '\\\\'\n"
"#define N_SYMBOL 'n'\n"
"\n"
"void fill_codify_lines(buffered_string destination, const_string lines) {\n"
"    if (*lines == 0) {\n"
"        return;\n"
"    }\n"
"    else if (*lines == ENTER) {\n"
"        *destination++ = SLASH;\n"
"        *destination++ = N_SYMBOL;\n"
"        *destination++ = DOUBLE_QUOTE;\n"
"        *destination++ = ENTER;\n"
"        if (lines[1] != 0)\n"
"            *destination++ = DOUBLE_QUOTE;\n"
"        fill_codify_lines(destination, lines + 1);\n"
"    }\n"
"    else if (*lines == SLASH) {\n"
"        *destination++ = SLASH;\n"
"        *destination++ = SLASH;\n"
"        fill_codify_lines(destination, lines + 1);\n"
"    }\n"
"    else if (*lines == DOUBLE_QUOTE) {\n"
"        *destination++ = SLASH;\n"
"        *destination++ = DOUBLE_QUOTE;\n"
"        fill_codify_lines(destination, lines + 1);\n"
"    }\n"
"    else {\n"
"        *destination++ = *lines;\n"
"        fill_codify_lines(destination, lines + 1);\n"
"    }\n"
"}\n"
"\n"
"/*\n"
" * We need to format the lines of code\n"
" */\n"
"buffered_string codify_lines(buffered_string buffer, const_string source_code_lines) {\n"
"    *buffer = DOUBLE_QUOTE;\n"
"    fill_codify_lines(buffer + 1, source_code_lines);\n"
"    return buffer;\n"
"}\n"
"\n"
"int main() {\n"
"    char printing_buffer[PROGRAM_MAXIMUM_SIZE];\n"
"    bzero(printing_buffer, PROGRAM_MAXIMUM_SIZE);\n"
"    /*\n"
"     * Here we print the source code of the program\n"
"     */\n"
"    const_string full_source_code = write_source_code_to_buffer(printing_buffer);\n"
"    write(1, full_source_code, strlen(full_source_code));\n"
"    return 0;\n"
"}\n"
"\n"
"buffered_string write_source_code_to_buffer(buffered_string output_buffer) {\n"
"    char buffer[PROGRAM_MAXIMUM_SIZE];\n"
"    bzero(buffer, PROGRAM_MAXIMUM_SIZE);\n"
"    const_string other_source_code = get_other_source_code();\n"
"\n"
"    sprintf(output_buffer,\n"
"\"%s\"\n"
"\"const_string get_other_source_code() {\\n\"\n"
"\"    return\\n\"\n"
"\"%s\"\n"
"\";}\\n\",\n"
"other_source_code, codify_lines(buffer, other_source_code));\n"
"    return output_buffer;\n"
"}\n"
;}
