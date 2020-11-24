/* 
* Algorithmus and data structures
* Homework 04
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>

void display_menu() {
	printf("Выберите задание:\n\n");
	printf("1:\tКоличество маршрутов с препятствиями\n");
	printf("2:\tМаксимальная последовательность\n");
	printf("3:\tКонь обходит шахматную доску\n");
	printf("0:\tЗавершить программу\n");
	printf(">\t");
}

void print2(int n, int m, int a[n][m]) {
	int i, j;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				printf ("%4d", a[i][j]);
			printf ( "\n" );
		}
}

int main() {
	int map[3][3] = {{1, 1, 1},
									 {0, 1, 0},
									 {0, 1, 0}};
	int way[3][3];
	int sequence[10][11];
	char first[11] = {'g','e','e','k','b','r','a','i','n','s'};
	char second[11] = {'g','e','e', 'k', 'm', 'i', 'n', 'd', 's'};
	int i, j, k;
	int selector = 0;
	do {
		display_menu();
		scanf("%i", &selector);
		getchar();	// clear stdin
		switch (selector) {
			case 1:
				for (j = 0; j < 3; j++) {
					if (map[0][j] == 1)
						way[0][j] = 1;
					else
						way[0][j] = 0;
				}
				for (i = 1; i < 3; i++) {
					if (map[i][0] == 1)
						way[i][0] = 1;
					else
						way[i][0] = 0;
					for (j = 1; j < 3; j++)
						if (map[i][j] == 1)
							way[i][j] = way[i][j - 1] + way[i - 1][j];
						else
							way[i][j] = 0;
				}
				print2(3, 3, way);
				break;
			case 2:
			/*
			* что-то не работает цикл k++, идея в том, что если символы совпали,
			* заполнить строку предыдущим значением на этой строке.
			*/
				for (j = 0; j < 11; j++)	//Horizontal
					sequence[0][j] = 0;
				for (i = 0; i < 10; i++)	//Vertical
					sequence[i][0] = 0;
				for (i = 1; i < 10; i++)
					for (j = 1; j < 11; j++)
						if (first[j - 1] == second[i - 1]) {
							sequence[i][j] = sequence[i - 1][j] + 1;
							for (k = j; k < 10; k++)
								sequence[i][k + 1] = sequence[i][k];
							printf("Match %d %d\n", i, j);
							print2(10, 11, sequence);
						} else {
//							sequence[i][j] = sequence[i - 1][j];
							sequence[i][j] = sequence[i][j - 1];
							printf("Not match %d %d\n", i, j);
							print2(10, 11, sequence);
						}
				print2(10, 11, sequence);
				break;
			case 3:
			/*
			* интересная задача, но не успеваю, сделаю позже
			*/
				break;
			case 0:
				break;
		}
	} while (selector != 0);
	return 0;
}
