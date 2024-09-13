#include <iostream>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    int max_a, min_a, size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int summ = 0;
    int *arr_summ;
    arr_summ = (int*)malloc(size * sizeof(int));
    int **a;
    a = (int**)malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        a[i] = (int*)malloc(size * sizeof(int));
    }

   

    printf("\nМассив: \n");
    for (int i = 0; i < size; i++)
    {   
        for (int j = 0; j < size; j++)
        {
            a[i][j] = rand()%100;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    };
    printf("\n");
    
    for (int i = 0; i < size; i++)
    {   
        for (int j = 0; j < size; j++)
        {
            summ = summ + a[i][j];
        }
        arr_summ[i] = summ;
        printf("Сумма %d строки: %d\n", i+1, summ);
        summ = 0;
    };

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr_summ[i]);
    }
    

    return 0;
}