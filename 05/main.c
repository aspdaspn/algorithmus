/* 
* Algorithmus and data structures
* Homework 05
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define StringSize 81
#define StackSize StringSize

char Stack[StackSize];
int sp = -1;

void display_menu() {
	printf("Select the task:\n\n");
	printf("1: \tBraces Sequence\n");
	printf("2: \tReverse Polish Notation\n");
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

struct component {
	char value;
	struct component *p_next;
};
typedef struct component Component;

struct dstack {
	Component *p_head;
	int size;
	int maxSize;
};
struct dstack DStack;

void push_dstack(char c) {
	if (DStack.size < DStack.maxSize) {
		Component *p_tmp = (Component *) malloc(sizeof(Component));
		p_tmp -> value = c;
		p_tmp -> p_next = DStack.p_head;
		DStack.p_head = p_tmp;
		DStack.size++;
	} else
			printf("Error stack size\n");
}

char pop_dstack() {
	char c;
	if (DStack.size != 0) {
		Component *p_next = NULL;
		c = DStack.p_head -> value;
		p_next = DStack.p_head;
		DStack.p_head = DStack.p_head -> p_next;
		free(p_next);
		DStack.size--;
		return c;
	} else 
			return '~';	
}

void print_stack() {
	Component *p_current = DStack.p_head;
	while (p_current != NULL) {
		printf(" %c ", p_current -> value);
		p_current = p_current -> p_next;
	}
}

// Обратная польская запись
void rpn() {
	char ts[StringSize];
	int i = 0;
	int j = 0;
	char tmp;
	DStack.maxSize = 100;
	DStack.p_head = NULL;
	DStack.size = 0;
	printf("Enter infix string: ");
	fgets(ts, sizeof(ts) / sizeof(char), stdin);
	for (i = strlen(ts)-1; i > -1; i--)
		if (ts[i] == '\r' || ts[i] == '\n')
			ts[i] = 0;
		else
			break;
	printf("Postfix notation: ");	
	i = 0;
	while (ts[i] != '\0') {
		int numprint = 0;
		while (ts[j] != '-' && ts[j] != '+' && ts[j] != '/' && ts[j] != '*' && ts[j] != '(' && ts[j] != ')' && ts[j] != '\0') {
			if (ts[j] >= '0' && ts[j] <= '9') {
				printf("%c", ts[j]);
				numprint++;
			}
			j++;
		}
		if (numprint)
			printf(", ");
		if (ts[j] == '(')
			push_dstack(ts[j]);
		else if (ts[j] == '+' || ts[j] == '-') {
			tmp = pop_dstack();
			if (tmp == '(')
				push_dstack(tmp);
			if (tmp == '~' || tmp == '(')
				push_dstack(ts[j]);
			else if (tmp == '-' || tmp == '+') {
				printf(" %c ", tmp);
				push_dstack(ts[j]);
			}
			else if (tmp == '/' || tmp == '*') {
				printf(" %c ", tmp);
				push_dstack(ts[j]);
			}
		}
		else if (ts[j] == '*' || ts[j] == '/') {
			tmp = pop_dstack();
			if (tmp == '(')
				push_dstack(tmp);
			if (tmp == '~' || tmp == '(')
				push_dstack(ts[j]);
			else if (tmp == '-' || tmp == '+') {
				push_dstack(tmp);
				push_dstack(ts[j]);
			}
			else if (tmp == '*' || tmp == '/') {
				printf(" %c ", tmp);
				push_dstack(ts[j]);
			}
		}
		else if (ts[j] == ')') {
			tmp = pop_dstack();
			while (tmp != '(') {
				printf(" %c ", tmp);
				tmp = pop_dstack();
			}
		}
		else if (ts[j] == '\0')
			break;
		j++;
		i = j;
	}
	print_stack();
	printf(" \n");
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
			case 2:
				rpn();
				break;
			case 0:
				break;
		}
	} while (selector != 0);
	return 0;
}
