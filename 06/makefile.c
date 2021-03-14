/* 
 * Write random integer to file
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *p_file;

int main(){
	int count = 100;
	int t;
	p_file = fopen("file.dat", "w");
	if (p_file == NULL) {
		printf("Can't open file\n");
		return 1;
	}
	srand(time(NULL));
	while (count > 0) {
		t = rand() % 100;
		putc(t, p_file);
		count--;
	}
	fclose(p_file);
	return 0;
}
