#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define ROW 9
#define COL 9

int task1(void);
int task2(void);
int task3(void);

int main(void) {
	setlocale(LC_CTYPE, "RUS");
	task1();
	task2();
	task3();
	return 0;
}

int task1(void) {
	int row, col;
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
	
		for (col = 1; col <= COL; col++)
		{
			printf("%d + %d = %2d\t", row, col, row + col);
		}
		printf("\n");
	}

	system("pause"); 
	return 0;
}

int task2(void) { // 12 вар
    char a;

    do {
        int c;
        int pos = 1;           // Позиция разряда 
        int sum_even = 0;      // Сумма цифр на четных позициях
        int sum_odd = 0;       // Сумма цифр на нечетных позициях

        printf("\nВведите число: ");

        while ((c = getchar()) != '\n') {
            // Цифра ли символ
            if (c >= '0' && c <= '9') {
                int digit = c - '0'; // символ в число

                // Нечетный разряд 
                if (pos % 2 != 0) {
                    sum_odd += digit;
                }
                // Четный разряд 
                else {
                    sum_even += digit;
                }

                pos++;
            }
        }
        printf("Сумма нечетных разрядов: %d\n", sum_odd);
        printf("Сумма четных разрядов:   %d\n", sum_even);
        printf("Произведение сумм:       %d * %d = %d\n", sum_odd, sum_even, sum_odd * sum_even);

        while ((c = getchar()) != '\n' && c != EOF) {}

        printf("Продолжить? (Да - y, Нет - n): ");
        a = getchar(); 

    } while (a == 'y'); 

    return 0;
}
int task3(void) { 
    char symbol;
    int d1, d2, angle;
    int repeat = 1;

    while (repeat != 0) {
        printf("\nВведите символ из которого будет строиться фигура:\n");
        scanf(" %c", &symbol);

        printf("Введите высоту (d1):\n");
        scanf("%d", &d1);

        printf("Введите ширину (d2):\n");
        scanf("%d", &d2);

        printf("Введите угол a:\n");
        scanf("%d", &angle);

        if (d1 < 3 || d2 < 3) {
            printf("Слишком маленькие размеры! 3 минимальное значение!.\n");
        }
        else {
            printf("\nЧетырехугольник (пустой):\n\n");

            double slope = tan(angle * 3.14159265 / 180.0);
            if (slope > 1.5) slope = 1.5; // Ограничитель, чтобы не уехало за экран
            if (slope < 0) slope = 0;

            for (int i = 0; i < d1; i++) {
                // наклон вычисляя отступ слева
                int left_spaces = (int)(i * slope);
                for (int s = 0; s < left_spaces; s++) {
                    printf(" ");
                }

                if (i == 0 || i == d1 - 1) {
                    // верхняя и нижняя грани 
                    for (int j = 0; j < d2; j++) {
                        printf("%c", symbol);
                    }
                }
                else {
                    // боковые грани (пустота внутри)
                    printf("%c", symbol); // левая граница
                    for (int j = 1; j < d2 - 1; j++) {
                        printf(" "); // пустота
                    }
                    printf("%c", symbol); // правая граница
                }
                printf("\n");
            }
        }

        printf("\nПродолжить? (Да - введите любое число, Нет - введите 0):\n");
        scanf("%d", &repeat);
    }

    return 0;
}