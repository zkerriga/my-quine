#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define PROGRAM_MAXIMUM_SIZE 10240

typedef char *          buffered_string;
typedef const char *    const_string;

buffered_string write_source_code_to_buffer(buffered_string output_buffer);
const_string    get_other_source_code();

#define DOUBLE_QUOTE 34
#define ENTER 13
#define SLASH 92
#define N_SYMBOL 110

void fill_codify_lines(buffered_string destination, const_string lines) {
    if (*lines == 0) {
        *destination = DOUBLE_QUOTE;
        return;
    }
    else if (*lines == ENTER) {
        *destination++ = DOUBLE_QUOTE;
        *destination++ = SLASH;
        *destination++ = N_SYMBOL;
        *destination++ = ENTER;
        *destination++ = DOUBLE_QUOTE;
        fill_codify_lines(destination, lines + 1);
    }
    else if (*lines == DOUBLE_QUOTE) {
        *destination++ = SLASH;
        *destination++ = DOUBLE_QUOTE;
        fill_codify_lines(destination, lines + 1);
    }
    else {
        *destination = *lines;
        fill_codify_lines(destination + 1, lines + 1);
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
"%s\n"
";}\n\n",
other_source_code, codify_lines(buffer, other_source_code));
    return output_buffer;
}

const_string get_other_source_code() {
    return
""
;}
