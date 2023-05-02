/*
Вывод для x86-64 gcc 9.2
i = 2
i = ptr2 = 3

Вывод для x86-64 gcc 12.2.1
i = 3
i = ptr2 = 3

Неопределённое поведение - поведение, зависящее от компилятора
*/


#include <stdio.h>

int main()
{
	const int i = 2;
	const int* ptr1 = &i;
	int* ptr2 = (int*)ptr1;
	*ptr2 = 3;
	printf("i = %d\n", i);
	printf("i = ptr2 = %d", *ptr2);
	return 0;
}