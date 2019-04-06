/* Шадрин Александр
 */

#include <stdio.h>

/* Задача 1
 * Попробовать оптимизировать пузырьковую сортировку.
 * Сравнить количество операций сравнения
 * оптимизированной и не оптимизированной программы.
 * Написать функции сортировки, которые
 * возвращают количество операций.
 */

void print(int n, int * a)
{
	for (int i=0; i<n; ++i)
		printf("%6i", a[i]);
	printf("\n");
}

// Пузырьковая сортировка
int bubble_a()
{
	int a[10] = {8, 1, 0, 9, 3, 4, 2, 5, 7, 6}, n, i, j;
	//printf("Enter nums (10-100):\n");
	//scanf("%d", &n);
	// for (i=0; i<n; ++i) scanf("%d", &a[i]);
	n = 10;
	printf("\tМассив до сортировки\n");
	print(n, a);
	for (i=0; i<n; ++i)
		for (j=0; j<n-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	printf("\tМассив поле сортировки\n");
	print(n, a);
	return i*j;
}

//Оптимизированныя пузырьковая сортировка
int bubble_b()
{
	int a[10] = {8, 1, 0, 9, 3, 4, 2, 5, 7, 6}, n, i, j, c;
	printf("Enter nums (10-100):\n");
	//scanf("%d", &n);
	//for (i=0; i<n; ++i) scanf("%d", &a[i]);
	n = 10;
	printf("\tМассив до сортировки\n");
	print(n, a);
	for (i=0; i<n; ++i)
	{
		c = 0;
		for (j=0; j<n-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				++c;
			}
		}
		if (c <= 1) break;
	}
	printf("\tМассив после сортировки\n");
	print(n, a);
	return i*j;
}

void task_1()
{
	int counter;
	printf("Пройдено итераций\n");
	counter = bubble_a();
	printf("Пузырьковой сортировкой: %d\n", counter);
	counter = bubble_b();
	printf("Пузырьковой оптимизированной сортировкой: %d\n", counter);
}

/* 3. Реализовать бинарный алгоритм поиска в виде
 * функции, которой передается отсортированный
 * массив. Функция возвращает индекс найденного
 * элемента или -1, если элемент не найден.
 */

int b_search(int n, int * a)
{
	int num;
	printf("Введите цифру для поиска");
	scanf("%d", &num);
	int I = -1;
	int L = 0;
	int R = n-1;
	int M = L + (R-L)/2;
	printf("Старт цикла\n");
	for (int i; ((L<=R) || (a[M]!=num)); M=L+(R-L)/2)
	{
		printf("Цикл запущен\n");
		if (a[M] < num) L = M + 1;
		else R = M-1;
	}
	if (a[M] == num) return M;
	else return -1;
}

void task_2()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	index = b_search(10, a)
	if (index != -1)
		printf("Индекс найденного элемента: %d\n", index);
	else printf("Не найдено\n");
}

int main(int argc, char const *argv[])
{
	/* code */
	task_2();
	return 0;
}