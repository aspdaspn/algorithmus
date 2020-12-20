/* 
* Algorithmus and data structures
* Homework 05
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>
#define StringSize 81
#define StackSize StringSize

char Stack[StackSize];
int sp = -1;

void display_menu() {
	printf("Select the task:\n\n");
	printf("1: \tBraces Sequence\n");
	printf("0: \tExit\n");
	printf(">\t");
}

void push(char c) {
	if (sp < StackSize) {
		sp++;
		Stack[sp] = c;
	}
}

char stack_top() {
	if (sp != -1)
		return Stack[sp];
	else
		printf("Stack is empty!\n");
}

char pop() {
	if (sp != -1)
		return Stack[sp--];
	else
		printf("Stack is empty!\n");
}

//Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. 
// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), 
// неправильных — )(, ())({), (, ])}), ([(]) для скобок [, (, {.
// Например: (2+(2*2)) или [2/{5*(4+7)}].
void check_braces() {
	char ts[StringSize];
	int i = 0;
	
	printf("Enter test string:");
	fgets(ts, sizeof(ts) / sizeof(char), stdin);
	while (ts[i] != '\0') {
		if (ts[i] == '(' || ts[i] == '[' || ts[i] == '{')
			push(ts[i]);
		if (ts[i] == ')' || ts[i] == ']' || ts[i] == '}')
			switch(stack_top()) {
				case '(':
					if (ts[i] == ')')
						pop();
					break;
				case '[':
					if (ts[i] == ']')
						pop();
					break;
				case '{':
					if (ts[i] == '}')
						pop();
					break;
			}
		i++;
	}
	printf("%s\n", (sp == -1) ? "Braces are correct" : "Braces are wrong"); 
}

int main() {
	int selector = 0;
	do {
		display_menu();
		scanf("%d", &selector);
		getchar();
		switch (selector) {
			case 1:
				check_braces();
				break;
			case 0:
				break;
		}
	} while (selector != 0);
	return 0;
}
