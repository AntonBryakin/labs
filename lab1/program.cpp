#include <iostream>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    int max_a, min_a;
    int summ = 0;
    int a[5][5];

    printf("\nМассив: \n");
    for (int i = 0; i < 5; i++)
    {   
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand()%100;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    };
    printf("\n");
    for (int i = 0; i < 5; i++)
    {   
        for (int j = 0; j < 5; j++)
        {
            summ = summ + a[i][j];
        }
        printf("Сумма %d строки: %d\n", i+1, summ);
        summ = 0;
    };

    return 0;
}