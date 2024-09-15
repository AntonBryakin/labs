#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i=0, j=0, r, yk=0, size=0;

    int num[] = {100,200,400,1000,2000,4000};

    while (size != 4000)
    {
        size = num[yk];
        yk++;

	    int **a, **b, **c, elem_c;
        
        a = (int**)malloc(size * sizeof(int*));
        b = (int**)malloc(size * sizeof(int*));
        c = (int**)malloc(size * sizeof(int*));

        for (int i = 0; i < size; i++)
        {
            a[i] = (int*)malloc(size * sizeof(int));
            b[i] = (int*)malloc(size * sizeof(int));
            c[i] = (int*)malloc(size * sizeof(int));
        }

        srand(time(NULL)); // инициализируем параметры генератора случайных чисел
        while(i<size)
        {
            while(j<size)
            {
                a[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
                b[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
                j++;
            }
            i++;
        }
        srand(time(NULL)); // инициализируем параметры генератора случайных чисел
        i=0; j=0;

        int starttime = clock();
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                elem_c=0;
                for(r=0;r<size;r++)
                {
                    elem_c=elem_c+a[i][r]*b[r][j];
                    c[i][j]=elem_c;
                }
            }
        }
        float diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);

        printf("При размере матрицы %d на %d, время выполнения: %f\n", size, size, diff);
        free(a);
        free(b);
        free(c);
    }


	return(0);
}
