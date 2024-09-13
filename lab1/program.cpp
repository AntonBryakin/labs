#include <iostream>
#include <stdlib.h>

int main() {

    int max_a, min_a;
    int a[10]; 

    min_a = max_a = a[0];

    printf("Массив: ");
    for (int i = 1; i <= 9; i++)
    {
        a[i] = rand()%100;
        if (a[i] > max_a) {
            max_a = a[i];
        };
        if (a[i] < min_a) {
            min_a = a[i];
        };

        printf("%d ",a[i]);
    }
    
    printf("\nМаксимальное число в массиве: %d\nМинимальное число в массиве: %d", max_a,min_a);

    return 0;
}