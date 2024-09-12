#include <iostream>

int main() {

    int max_a, min_a;
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

    min_a = max_a = a[0];

    for (int i = 1; i <= 9; i++)
    {
        if (a[i] > max_a) {
            max_a = a[i];
        };
        if (a[i] < min_a) {
            min_a = a[i];
        };
    }
    
    printf("Максимальное число в массиве это: %d\nМинимальное число в массиве это: %d", max_a,min_a);

    return 0;
}