/* 
* Algorithmus and data structures
* Homework 01
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>
#include <math.h>

void display_menu() {
	printf("Выберите задание:\n\n");
	printf("1:\tРасчёт индекса массы тела\n");
	printf("2:\tНаибольшее из четырёх чисел\n");
	printf("3:\tРешение квадратного уравнения\n");
	printf("4:\tВремена года\n");
	printf("5:\tВозраст человека\n");
	printf("6:\tЦвет шахматной клетки\n");
	printf("7:\tКвадраты и кубы чисел от a до b\n");
	printf("0:\tЗавершить программу\n");
	printf(">\t");
}

/*
* Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); 
* где m-масса тела в килограммах, h - рост в метрах.
*/
void calc_bmi(){
	float m, h;
	do {
		printf("Введите рост в метрах: \n");
		scanf("%f", &h);
		printf("Введите вес в килограммах: \n");
		scanf("%f", &m);
	} while ((m <= 0 || m > 300) || (h <= 0 || h > 3));
	printf("Ваш индекс массы тела: %.1f\n", m / (h * h));
}

// Замена двух переменных
void swap_integer(int *a, int *b) {
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

// Найти максимальное из четырех чисел. Массивы не использовать.
void greater_of_four() {
	int a, b, c, d;
	printf("Введете четыре целых числа: \n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a < b)
		swap_integer(&a, &b);
	if (c < d)
		swap_integer(&c, &d);
	if (a < c)
		swap_integer(&a, &c);
	printf("Наибольшее число: %d\n", a);
}

// Решение квадратного уравнения
int calcSquareEq(int a, int b, int c, double* x1, double* x2) {
	// Проверим что пользователь не ввёл что-то вида 0x^2 + b*0 + 5 = 0
	if ((a == 0) && (b == 0) && (c != 0))
		return -1;
	// Проверка на случай ввода 0*x^2 + 2*x + c = 0
	if ((a == 0) && (b != 0)) {
		*x1 = (double)-c / b;
		return 0;
	}
	int d;
	// Посчитаем дискриминант и определим число корней:
	// d < 0, нет корней, возвращаем -1
	// d > 0, два корня, посчитаем x2 и x1 и вернём 1
	// d = 0, один корень, посчитаем х1 и вернём 0
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
		return -1;
	else {
		if (d > 0)
			*x2 = (-b - sqrt(d)) / (2 * a);
		*x1 = (-b + sqrt(d)) / (2 * a);
		return (d > 0) ? 1 : 0;
	}
}

// Запрос параметров уравнения и вывод
void quadratic_equatation() {
	int a, b, c;
	double x1 = 0;
	double x2 = 0;
	int	diskr;
	char input;
	printf("Квадратное уравнение вида ax^2 + bx + c = 0\n");
	do {
		printf("Введите a, b, c через пробел без запятых: ");
		scanf("%d %d %d", &a, &b, &c);
		printf("Уравнение %dx^2 %s %dx %s %d = 0 ", a, (b < 0) ? "" : "+", b, (c < 0) ? "" : "+", c);
		diskr = calcSquareEq(a, b, c, &x1, &x2);
		if (diskr == -1)
			printf("не имеет корней!\n");
		else {
			printf("имеет %d кор%s\n", diskr + 1, (diskr > 0) ? "ня:\n" : "ень:\n");
			printf("x1 = %.2f\n", x1);
			if (diskr > 0)
				printf("x2 = %.2f\n", x2);
		}
		printf("Посчитать ещё? (y/n): ");
		scanf("%s", &input);
	}	while (input == 'y');
}

// С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
void seasons() {
	int m;
	do {
		printf("Введите номер месяца или 0 для выхода: \n");
		scanf("%d", &m);
		switch (m) {
			case 12:
				printf("Зима\n");
				break;
			case 1:
				printf("Зима\n");
				break;
			case 2:
				printf("Зима\n");
				break;
			case 3:
				printf("Весна\n");
				break;
			case 4:
				printf("Весна\n");
				break;
			case 5:
				printf("Весна\n");
				break;
			case 6:
				printf("Лето\n");
				break;
			case 7:
				printf("Лето\n");
				break;
			case 8:
				printf("Лето\n");
				break;
			case 9:
				printf("Осень\n");
				break;
			case 10:
				printf("Осень\n");
				break;
			case 11:
				printf("Осень\n");
				break;
		}
	} while (m != 0);
}

// Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void human_age() {
	int age, ld;
	do {
		printf("Введите возраст (1 ... 150): \n");
		scanf("%d", &age);
	} while (age < 1 || age > 150);
	
	ld = age % 10;
	printf("Введённый возраст: %d ", age);
	if ((age > 10 && age < 20) || (age > 110 && age < 120))
		printf("лет\n");
	else if (ld == 1) printf("год\n");
	else if (ld == 2 || ld == 3 || ld == 4) printf("года\n");
	else printf("лет\n");
}

// С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). 
// требуется определить, относятся ли к поля к одному цвету или нет.
void chess_square_color() {
	char sq1[5];
	char sq2[5];
	do {	
		fflush(stdin);
		printf("\nВведите первую клетку, например Е2: ");
		fgets(sq1, sizeof(sq1), stdin);
	} while ((sq1[0] < 0x41 || sq1[0] > 0x48) || (sq1[1] < '1' || sq1[1] > '8'));
	do {	
		fflush(stdin);
		printf("\nВведите вторую клетку, например H8: ");
		fgets(sq2, sizeof(sq2), stdin);
	} while ((sq2[0] < 0x41 || sq2[0] > 0x48) || (sq2[1] < '1' || sq2[1] > '8'));
	printf("Клетка %c%c", sq1[0], sq1[1]);
	printf(" %s\n", ((sq1[0] + sq1[1]) % 2 == 0) ? "чёрная" : "белая"); 
	printf("Клетка %c%c", sq2[0], sq2[1]);
	printf(" %s\n", ((sq2[0] + sq2[1]) % 2 == 0) ? "чёрная" : "белая"); 
	fflush(stdin);
}

// Ввести a и b и вывести квадраты и кубы чисел от a до b.
void squares_and_cubes() {
	int a, b, i;
	do {
		printf("Введите число a: ");
		scanf("%d", &a);
		printf("Введите число b: ");
		scanf("%d", &b);
	} while (a > b);
	printf("i\tКвадрат\tКуб\n");
	for (i = a; i < b; i++) {
		printf("%d\t%.0f\t%.0f\n", i, pow(i, 2), pow(i, 3));
	}

	
}

int main() {
	int selector = 0;
	do {
		display_menu();
		scanf("%i", &selector);
		getchar();	// clear stdin
		switch (selector) {
			case 1:
				calc_bmi();
				break;
			case 2:
				greater_of_four();
				break;
			case 3:
				quadratic_equatation();
				break;
			case 4:
				seasons();
				break;
			case 5:
				human_age();
				break;
			case 6:
				chess_square_color();
				break;
			case 7:
				squares_and_cubes();
				break;
			case 0:
				break;
		}
	} while (selector !=0);

	return 0;
}
