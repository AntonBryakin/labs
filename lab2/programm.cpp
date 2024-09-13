#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int *items, int count) {
    int i, j, gap, k;
    int x, a[5];

    a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

    for(k=0; k < 5; k++) {
        gap = a[k];
        for(i=gap; i < count; ++i) {
        x = items[i];
        for(j=i-gap; (x < items[j]) && (j >= 0); j=j-gap)
            items[j+gap] = items[j];
        items[j+gap] = x;
        }
    }
}

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

    int arr_rand[200];
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        arr_rand[i] = rand()%200+1;
    }
    
    int arr_up[200];
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        arr_up[i] = i;
    }
    
    int arr_down[200];
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        arr_up[i] = 200 - i;
    }

    int arr_upDown[200];
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        if (i<100)
            arr_upDown[i] = i;
        else 
            arr_upDown[i] = 200-i;
    }

    shell(arr_rand,200);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr_rand[i]);
    }
    
	return(0);
}
