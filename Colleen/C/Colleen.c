#include <string.h>
#include <unistd.h>

typedef const char *	const_string;

const_string process_on_source_code(const_string source_code);
const_string get_source_code();
const_string get_other_source_code();

/*
 * Here we are working with an unprepared source code
 * so that it is identical to the real one
 */
const_string process_on_source_code(const_string source_code) {
	return source_code;
}

int main() {
	/*
	 * Here we print the source code of the program
	 */
	const_string full_source_code = process_on_source_code(get_source_code());
	write(1, full_source_code, strlen(full_source_code));
	return 0;
}

const_string get_source_code() {
	const_string other_source_code = get_other_source_code();
	return other_source_code;
}

const_string get_other_source_code() {
	return "PASS";
}