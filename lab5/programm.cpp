#include <stdio.h>
#include <random>
#include <time.h>

int factorial (int n){
    return (n < 2) ? 1 : n * factorial (n - 1);
}

int main() {
    srand(time(NULL));
    int n, **G=NULL, sizeGraf = 0, countIzol = 0, countDom = 0, countEnd = 0;

    printf("Введите количество вершин графа:");
    scanf("%d",&n);


    G = (int **)malloc(n*sizeof(int*));

    for (int i=0; i<n; i++)
        G[i] = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            G[i][j] = 0;
    
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            G[i][j] = rand()%2;
            G[j][i] = G[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (G[i][j] == 1) 
                sizeGraf++; 
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
    printf("Размер графа равен %d \n", sizeGraf);

    for (int i=0; i<n; i++){
        int sizeStr = 0;
        countDom = 0;
        countIzol = 0;
        countEnd = 0;
        for (int j = 0; j<n; j++){
            if ((G[i][j] == 1) and (i != j)) sizeStr = sizeStr + 1;
        }
        if (sizeStr == 0) printf("Вершина %d изолированная\n", i+1);
        if (sizeStr == 1) printf("Вершина %d концевая\n", i+1);
        if (sizeStr >= n-1) printf("Вершина %d доминирующая\n", i+1);
    }

    return 0;
}