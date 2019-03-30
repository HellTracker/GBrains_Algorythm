/* Задача 4
 * Написать программу нахождения корней заданного квадратного уравнения.
 */

#include <stdio.h>
#include <math.h>

void eQuad(double a, double b, double c)
{
	double d, x1, x2, xi1, xi2;
	d = b*b - 4*a*c;
	if (d == 0)
	{
		x1 = x2 = (-b + sqrt(d))/(2*a);
		printf("Уравнение имеет один корень: %.2lf\n", x1);
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d))/(2*a);
		x2 = (-b - sqrt(d))/(2*a);
		printf("Уравнение имеет два корня: %.2lf и %.2lf\n", x1, x2);
	}
	else if (d < 0)
	{
		x1 = x2 = (-b)/(2*a);
		xi1 = sqrt(4*a*c - b*b);
		xi2 = -sqrt(4*a*c - b*b);
		printf("Уравнение имеет два корня: %.2lf + i%.2lf и %.2lf - i%.2lf\n", x1, xi1, x2, xi2);
	}
}

void eLine(double b, double c)
{
	double x;
	printf("Это линейное уравнение!\n");
	x = b/(-c);
	printf("Имеет 1 корень %.2lf\n", x);
}

int main(int argc, char const *argv[])
{
	/* code */
	double a, b, c, x;
	printf("Решатель уравнения вида\n");
	printf("A*x^2 + B*x + C = 0\n\n");
	printf("Введите A, B и C:\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a > 0) eQuad(a,b,c);
	else if ((a == 0) && (c != 0) && (b != 0)) eLine(b,c);
	else if ((a == 0) && (c == 0)) printf("Бесконечное множество корней\n");

	return 0;
}
