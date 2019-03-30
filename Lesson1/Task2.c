/* Задача 2
 * Найти максимальное из четырех чисел. Массивы не использовать.
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	int a,b,c,d,max;
	printf("Введите 4 числа:\n");
	scanf("%d %d %d %d", &a,&b,&c,&d);
	if (a > b) max = a;
	if (b > c) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	printf("Максимальное число: %d\n", max);
	return 0;
}
