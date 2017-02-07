#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 10
typedef int (*calc)(int, int);

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main(int argc, char * argv[]) {
	
	calc calculate = NULL;
	int a, b;
	unsigned int i, j = 0;
	char raw_input[MAX_INPUT];
	char filtered_input[MAX_INPUT];
	char operands[5];
	char choice;
	const char delim[2] = ",";
	char * token;
	char operation_name[10];
	char operator;

	printf("\nPlease select from the following options followed\nby the terms seperated by a comma:\n\n");
	printf("%-20s: %c\n%-20s: %c\n%-20s: %c\n%-20s: %c\n\n",
				 "Addition", 'a', "Subtraction", 's', "Multiplication", 'm', "Division", 'd');

	printf("Input: ");

	/* get input */
	fgets(raw_input, MAX_INPUT, stdin);

	/* remove spaces */
	for (i = 0; i < strlen(raw_input); i++) {
		if (raw_input[i] != ' ') {
			filtered_input[j] = raw_input[i];
			j++;
		}
	}

	/* get option */
	choice = tolower(filtered_input[0]); 	

	/* get remainder of string */
	j = 0;
	for (i = 1; i < sizeof(filtered_input); i++) {
		operands[j] = filtered_input[i];
		j++;
	}

	token = strtok(operands, delim);
	a = (int)strtol(token, NULL, 10); /*convert token to int */
	token = strtok(NULL, delim);
	b = (int)strtol(token, NULL, 10); /*convert token to int */

	switch (choice) {
		case 'a':
			calculate = &add;
			strcpy(operation_name, "Addition");
			operator = '+';
			break;
		case 's':
			calculate = &subtract;
			strcpy(operation_name, "Subtraction");
			operator = '-';
			break;
		case 'm':
			calculate = &multiply;
			strcpy(operation_name, "Multiplication");
			operator = '*';
			break;
		case 'd':
			calculate = &divide;
			strcpy(operation_name, "Division");
			operator = '/';
			break;
		}

	printf("%s selected, %d %c %d = %d\n\n", operation_name, a, operator, b, calculate(a,b));

	return EXIT_SUCCESS;
}

int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
int divide(int a, int b) {
	return a / b;
}
