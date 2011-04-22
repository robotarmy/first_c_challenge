#include <stdio.h>
#include <assert.h>

void echo_char(c) {
	printf("You entered %c\n",c);
}
void print_prompt() {
	printf("Enter Character : . to quit\n");
}
char read_char() {
	char c;
	scanf("%c",&c);
	return c;
}
void eat_extra_input() {
	while (getchar() != '\n'); /* discard any other input upto newline */
}
struct record_s {
	char key;
	int value;
};
typedef struct record_s record;
#define MAX_REC 26
static record records[MAX_REC];
void record_init() {
	int i;
	for(i = 0; i < MAX_REC; i++) {
		records[i].key   = (97+i);
		records[i].value = 0;
	}
}
void record_char(char c) {
	assert(c-97 >= 0);
	assert(c-97 < MAX_REC);
}

void record_print() {
	int i = 0;
	printf("Records\n");	
	printf("KEY VALUE\n");
	for(i = 0; i < MAX_REC; i++) {
		printf("%3c %5d\n",records[i].key,records[i].value);
	}	
}
int main(int argc, char **argv) {
	char c = 0;
	record_init();
	while (c != '.') {
		print_prompt();
		c = read_char();
		eat_extra_input();
		if (c != '.') {
			record_char(c);
			echo_char(c);
		}
	}
	record_print();
	return 0;
}
