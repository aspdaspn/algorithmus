/* 
* Algorithmus and data structures
* Homework 02
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>

void display_menu() {
	printf("Выберите задание:\n\n");
	printf("1:\tПеревод из двоичной системы в десятичную\n");
	printf("2:\tВозведение числа в степень (цикл)\n");
	printf("3:\tВозведение числа в степень (рекурсия)\n");
	printf("4:\tИсполнитель калькулятор (массив)\n");
	printf("5:\tИсполнитель калькулятор (рекурсия)\n");
	printf("0:\tЗавершить программу\n");
	printf(">\t");
}

// Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
int dec2bin(int dec) {
	if (dec == 0)
		return 0;
	else
		return (dec % 2 + 10 * dec2bin(dec / 2));
}

// Реализовать функцию возведения числа a в степень b:
// a. без рекурсии;
// b. рекурсивно;
// c. *рекурсивно, используя свойство четности степени.
long power(int a, int b) {
	long p = 1;
	while (b) {
		p = p * a;
		b--;
	}
}

long pow_recurs(int a, int b) {
	if (b == 1)
		return a;
	else
		return (a * pow_recurs(a, --b));
}

/* Исполнитель «Калькулятор» преобразует целое число, записанное на экране. 
* У исполнителя две команды, каждой присвоен номер:
* 	1. Прибавь 1.
* 	2. Умножь на 2.
* Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза. Сколько
* существует программ, которые число 3 преобразуют в число 20:
* 	а. С использованием массива.
* 	b. *С использованием рекурсии.
*/
int calculator(int a, int b) {
	int size = b - a + 1;
	int programs[2][size];
	int i, c;
	for (i = 0; i < size; i++) { 
		programs[0][i] = a + i;
		if (programs[0][i] % 2 == 0)
			if (programs[0][i] / 2 < a)
				programs[1][i] = 1;
			else
				programs[1][i] = programs[1][i / 2 - 1] + programs[1][i - 1];
		else 
			if (i == 0)
				programs[1][i] = 1;
			else
				programs[1][i] = programs[1][i - 1];
	}
	return programs[1][b - a];
}

int calculator_recurs(int a, int b) {
	if (b <= a)
		return 0;
	if (b == a * 2)
		return 1 + calculator_recurs(a, b - 1);
	if (b == a + 1)
		return 1;
	if (b % 2 == 0)
		return calculator_recurs(a, b - 1) + calculator_recurs(a, b/2);
	else
		return calculator_recurs(a, b - 1);
}

int main() {
	int dec;
	int a, b;
	int selector = 0;
	do {
		display_menu();
		scanf("%i", &selector);
		getchar();	// clear stdin
		switch (selector) {
			case 1:
				printf("Введите целое число: \n");
				scanf("%d", &dec);
				printf("Двоичное число: %d\n", dec2bin(dec));
				break;
			case 2:
				printf("Введите число и степень\n");
				scanf("%d %d", &a, &b);
				printf("%ld\n", power(a, b));
				break;
			case 3:
				printf("Введите число и степень\n");
				scanf("%d %d", &a, &b);
				printf("%ld\n", pow_recurs(a, b));
				break;
			case 4:
				printf("Калькулятор от 3 до 20:\n");
				printf("%d\n", calculator(3, 20)); 
				break;
			case 5:
				printf("Калькулятор от 3 до 20:\n");
				printf("%d\n", calculator_recurs(3, 20)); 
				break;
			case 0:
				break;
		}
	} while (selector !=0);

	return 0;
}
