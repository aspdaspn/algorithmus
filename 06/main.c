/* 
* Algorithmus and data structures
* Homework 06
* by Ilya Nikolskiy
* 
* For all checking persons: this file was saved in UTF-8 encoding.
* Please consider this if Russian characters will be displayed incorrectly.
*/

#include <stdio.h>

int hash(char s[], int size) {
	int i, result;
	result = 0;
	for (i = 0; i < size; i++)
		result += (int) s[i];
	return result;
}

int main() {
	char string[] = {'T','e','s','t',' ','s','t','r','i','n','g'};
	printf("Hash: %d\n", hash(string, 11));
	return 0;
}
