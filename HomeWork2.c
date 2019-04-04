/* Шадрин Александр
 */

#include <stdio.h>

/* Реализовать функцию перевода из 10 системы
 * в двоичную используя рекурсию.
 */
void dec2bin(int dec)
{
	if (dec >= 2)
		dec2bin(dec/2);
	printf("%d", dec%2);
}

void task_1()
{
	int a;
	printf("Введите число в десятичной системе:\n");
	scanf("%d", &a);
	printf("Представляем в двоичной:\n");
	dec2bin(a);
}

/* Реализовать функцию возведения числа a в степень b
 * без рекурсии
 */
int power_a(int n, int p)
{
	int m = 1;
	if ((p != 0) && (n != 0))
	{

		while (p)
		{
			printf("%d\n", p);
			m*=n;
			--p;
			printf("%d\n", m);
		}		
		return m;
	}
	else if ((p == 0) && (n != 0)) return 1;
}

/* Реализовать функцию возведения числа a в степень b
 * рекурсивно
 */
int power_b(int n, int p)
{
	if ((p != 0) && (n != 0))
		return (n * power_b(n, p-1));
	else if ((p == 0) && (n != 0)) return 1;
}

void task_2()
{
	int a,b;
	printf("Введите число и степень:\n");
	scanf("%d %d", &a, &b);
	printf("%d\n", power_a(a, b));
	printf("%d\n", power_b(a, b));
}

/* Исполнитель Калькулятор преобразует целое число,
 * записанное на экране. У исполнителя две команды,
 * каждой команде присвоен номер:
 * 1. Прибавь 1.
 * 2. Умножь на 2.
 * Сколько существует программ, которые число 3
 * преобразуют в число 20?
 */

/*Решение с использованием массива
 * 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * 1 1 1 2 2 3 3  4  4  6  6  8  8 11 11 14 14>18<
 *                                            ^^^^
 * Xn = Xn-1
 * Xn = Xn-1 + Xn/2
 */
int calc_a()
{
	int array[20], i=4;
	array[2] = 0;
	array[3] = 1;
	for (i; i<=20; ++i)
	{
		if (i % 2 != 0) array[i] = array[i-1];
		else array[i] = array[i-1] + array[i/2];
	}
	printf("Количество итераций: %d\n", i-4);
	return array[20];
}

/* Решение с использованием рекурсии
 * 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
 * 1 1 1 2 2 3 3  4  4  6  6  8  8 11 11 14 14>18<
 *                                            ^^^^
 * Xn = Xn-1
 * Xn = Xn-1 + Xn/2
 */
int calc_b(int a, int b, int *i)
{
	++(*i);
	if (b < a) return 0;
	else if (b == a) return 1;
	else if (b % 2 != 0) return calc_b(a, b-1, i);
	else return calc_b(a, b-1, i) + calc_b(a, b/2, i);
}

void task_3()
{
	int i = 0;
	printf("Калькулятор A\n");
	printf("%d\n", calc_a());
	printf("Калькулятор B\n");
	printf("%d\n", calc_b(3, 20, &i));
	printf("Количество вызовов функции: %d\n", i);
}

int main(int argc, char const *argv[])
{
	/* code */
	task_3();
	return 0;
}
