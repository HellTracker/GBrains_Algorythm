/* Задача 3
 * Написать программу обмена значениями двух целочисленных переменных:
 * a. с использованием третьей переменной;
 * b. *без использования третьей переменной.
 */

#include <stdio.h>

void fn_a(int * a, int * b)
{
	int c;
	c = *b;
	*b = *a;
	*a = c;
	printf("Число A: %d\nЧисло B: %d\n", *a, *b);
}

void fn_b(int * a, int * b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	printf("Число A: %d\nЧисло B: %d\n", *a, *b);
}

int main(int argc, char const *argv[])
{
	/* code */
	int a, b;
	printf("Введите число А: ");
	scanf("%d", &a);
	printf("Введите число B: ");
	scanf("%d", &b);
	fn_a(&a,&b);
	fn_b(&a,&b);
	return 0;
}