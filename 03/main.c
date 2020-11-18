/* 
* Algorithmus and data structures
* Homework 03
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10

void display_menu() {
	printf("Выберите задание:\n\n");
	printf("1:\tПузырьковая сортировка (обычная)\n");
	printf("2:\tПузырьковая сортировка (оптимизированная)\n");
	printf("3:\tШейкерная сортировка\n");
	printf("4:\tБинарный алгоритм поиска\n");
	printf("0:\tЗавершить программу\n");
	printf(">\t");
}

void swap_integer(int *a, int *b) {
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void generate_array(int *a, int size) {
	int i;
	srand(time(NULL));
	for (i = 0; i < size; i++)
		a[i] = rand() % 100 + 1;
}

// Асимптотическая сложность алгоритма O(N^2)
int bubble_sort(int *a, int size) {
	int i, j;
	int counter = 0;
	for (i = 0; i < size; i++)
		for (j = 0; j < size - 1; j++)
			if (a[j] > a[j + 1]) {
				swap_integer(&a[j], &a[j + 1]);
				counter++;
			}
	return counter;
}

// Асимптотическая сложность алгоритма O(N^2)
int bubble_sort_opt(int *a, int size) {
	int i = 0;
	int j = 0;
	int swapped = 1;
	int counter = 0;
	while (i < size && swapped == 1) {
		swapped = 0;
		for (j = 0; j < size - 1; j++)
			if (a[j] > a[j + 1]) {
				swap_integer(&a[j], &a[j + 1]);
				swapped = 1;
				counter++;
			}
		i++;
	}
	return counter;
}

// Асимптотическая сложность алгоритма O(N^2)
void shaker_sort(int *a, int size) {
	int l, r, i;
	l = 0;
	r = size - 1;
	while (l < r) {
		for (i = l; i < r; i++)
			if (a[i] > a[i + 1])
				swap_integer(&a[i], &a[i + 1]);
		for (i = r; i > l; i--)
			if (a[i - 1] > a[i])
				swap_integer(&a[i - 1], &a[i]);
		l++;
		r--;
	}
}

// Асимптотическая сложность алгоритма O(N)
int binary_search(int *a, int size, int value) {
	int l, r;
	l = 0;
	r = size - 1;
	int m = l + (r - l) / 2;
	while (l <= r && a[m] != value) {
		if (a[m] < value)
			l = m + 1;
		else
			r = m - 1;
		m = l + (r - l) / 2;
	}
	if (a[m] == value)
		return m;
	else
		return -1;
}

void print_array(int *a, int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d %d\n", i, a[i]);
}

int main() {
	int array[SIZE];
	int temp[SIZE];
	int guess;
	int selector = 0;
	do {
		display_menu();
		scanf("%i", &selector);
		getchar();
		switch (selector) {
			case 1:
				printf("Исходный массив:\n");
				generate_array(array, SIZE);
				print_array(array, SIZE);
				memcpy(&temp, &array, sizeof(array));
				printf("Перестановок: %d\n", bubble_sort(array, SIZE));
				printf("Отсортированный массив:\n");
				print_array(array, SIZE);
				break;
			case 2:
				printf("Исходный массив:\n");
				memcpy(&array, &temp, sizeof(array));
				print_array(array, SIZE);
				printf("Перестановок: %d\n", bubble_sort_opt(array, SIZE));
				printf("Отсортированный массив:\n");
				print_array(array, SIZE);
				break;
			case 3:
				printf("Исходный массив:\n");
				generate_array(array, SIZE);
				print_array(array, SIZE);
				shaker_sort(array, SIZE);
				printf("Отсортированный массив:\n");
				print_array(array, SIZE);
				break;
			case 4:
				printf("Исходный массив:\n");
				generate_array(array, SIZE);
				print_array(array, SIZE);
				shaker_sort(array, SIZE);
				printf("Отсортированный массив:\n");
				print_array(array, SIZE);
				printf("Введите число для поиска: ");
				scanf("%d", &guess);
				printf("Элемент по индексу %d\n", binary_search(array, SIZE, guess));
				break;
			case 0:
				break;
		}
	} while (selector != 0);

	return 0;
}
