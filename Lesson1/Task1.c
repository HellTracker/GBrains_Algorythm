/* Задача 1
 * Ввести вес и рост человека. Рассчитать и вывести индекс
 * массы тела по формуле I=m/(h*h); где m-масса тела в
 * килограммах, h - рост в метрах.
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	/* code */
	double I,m,h;
	printf("Введите сначала рост, затем вес\n");
	scanf("%lf %lf", &h, &m);
	while (1) // Проверка на более-менее реалистичный рост
	{
		if ((h > 3) && (h < 300))
		{
			printf("Конвертируем сантиметры в метры\n");
			h = h / 100;
			break;
		}
		else if ((h > 300) || (h < 0))
		{
			printf("Пожалуйста, введите корректный рост:\n");
			scanf("%lf", &h);
		}
		else if ((h < 3) && (h > 0)) break;
	}
	I = m/(h*h);
	printf("Рост: %.2lf Вес: %.2lf\n", h, m);
	printf("Индекс массы: %.2lf\n", I);
	return 0;
}
