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

int can_move(int x, int y, int b[8][8]) {
	if (x < 1 || x > 7 || y < 0 || y > 7) {
		printf("cannot move! x = %d y = %d\n", x, y);
		return 0;
	}
	else if (b[x][y] != 0) {
		printf("not empty cell! x = %d y = %d, value = %d\n", x, y, b[x][y]);
		return 0;
	}
	return 1;
}

int next_move(int x, int y, int b[8][8], int m[8][2], int move) {
	int i;
	int newX, newY;
	if (move > 64)
		return 0;
	else {
		b[x][y] = move;
		printf("%d %d %d %d\n", move, x, y, b[x][y]);
		for (i = 0; i < 8; i++) {
			newX = x + m[i][0];
			newY = y + m[i][1];
			if (can_move(newX, newY, b) && next_move(newX, newY, b, m, move + 1)) {
				b[x][y] = move;
				return move;
			} else {
				b[x][y] = 0;
			}
		}
	}
}
void knight_move() {
	int board[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0},
									 	 {0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0},
										 {0, 0, 0, 0, 0, 0, 0, 0}};

	int moves[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {1, -2},
										 {-1,  2}, { 2, -1}, { 1, 2}, {2,  1}};
	next_move(0, 0, board, moves, 1);
	print2(8, 8, board);
}

int main() {
	int map[3][3] = {{1, 1, 1},
									 {0, 1, 0},
									 {0, 1, 0}};
	int way[3][3];
	int sequence[10][11];	//row | column
	char first[11] = {'g','e','e','k','b','r','a','i','n','s','\0'};
	char second[10] = {'g','e','e','k','m','i','n','d','s','\0'};
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
				for (j = 0; j < 11; j++)
					sequence[0][j] = 0;
				for (i = 0; i < 10; i++)
					sequence[i][0] = 0;
				for (i = 1; i < 10; i++)
					for (j = 1; j < 11; j++)
						if (first[j - 1] == second[i - 1])
							sequence[i][j] = sequence[i - 1][j - 1] + 1;
						else 
							if (sequence[i][j - 1] >= sequence[i - 1][j])
								sequence[i][j] = sequence[i][j - 1];
							else
								sequence[i][j] = sequence[i - 1][j];
				print2(10, 11, sequence);
				printf("Максимальная длина последовательностей %s и %s: %d\n", first, second, sequence[9][10]);
				break;
			case 3:
				knight_move();
				break;
			case 0:
				break;
		}
	} while (selector != 0);
	return 0;
}
