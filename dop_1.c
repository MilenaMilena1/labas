/*
Функция swap_pointers создавала копии строк и работала с ними.
*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_nums(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap_pointers(char** x, char** y){
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}

int main(int argc, char* argv[]){
	int a = 3, b = 4;
	char* s1 = "I should print second";
	char* s2 = "I should print first";
	
	swap_nums(&a, &b);
	printf("a is %d\n", a);
	printf("b is %d\n", b);
	
	swap_pointers(&s1, &s2);
	
	printf("s1 is %s\n", s1);
	printf("s2 is %s\n", s2);
	return 0;
}
