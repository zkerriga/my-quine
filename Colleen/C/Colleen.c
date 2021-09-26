#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define PROGRAM_MAXIMUM_SIZE 10240

typedef char *	buffered_string;

buffered_string process_on_source_code(buffered_string source_code);
buffered_string get_source_code(buffered_string buffer);
buffered_string get_other_source_code(buffered_string buffer);

/*
 * Here we are working with an unprepared source code
 * so that it is identical to the real one
 */
buffered_string process_on_source_code(buffered_string source_code) {
	return source_code;
}

int main() {
	char buffer[PROGRAM_MAXIMUM_SIZE];
	bzero(buffer, PROGRAM_MAXIMUM_SIZE);
	/*
	 * Here we print the source code of the program
	 */
	buffered_string full_source_code = process_on_source_code(get_source_code(buffer));
	write(1, full_source_code, strlen(full_source_code));
	return 0;
}

buffered_string get_source_code(buffered_string buffer) {
	buffered_string other_source_code = get_other_source_code(buffer);
	sprintf(buffer, "%s PASS %s", other_source_code, other_source_code);
	return buffer;
}

buffered_string get_other_source_code(buffered_string buffer) {
	return strcat(buffer, "PASS");
}
