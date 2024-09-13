#include <iostream>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int max_a, min_a;
    int *a;
    a = (int*)malloc(size * sizeof(int));


    printf("\nМассив: ");
    for (int i = 0; i < size; i++)
    {   
        a[i] = rand()%100;
        if (i == 0) min_a = max_a = a[i];
        
        if (a[i] > max_a) {
            max_a = a[i];
        };
        if (a[i] < min_a) {
            min_a = a[i];
        };

        printf("%d ",a[i]);
    };
    free(a);
    printf("\nМаксимальное число в массиве: %d\nМинимальное число в массиве: %d", max_a,min_a);

    return 0;
}