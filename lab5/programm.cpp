#include <stdio.h>
#include <random>
#include <time.h>

int factorial (int n){
    return (n < 2) ? 1 : n * factorial (n - 1);
}

int main() {
    srand(time(NULL));
    int n, m=0, GI=NULL, **G=NULL, sizeGraf = 0;

    printf("Введите количество вершин графа:");
    scanf("%d",&n);


    G = (int )malloc(n*sizeof(int*));

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
        for (int j = 0; j<n; j++){
            if ((G[i][j] == 1) and (i!=j)) sizeStr++;
        }
        if (sizeStr == 0) printf("Вершина %d изолированная\n", i+1);
        if (sizeStr == 1) printf("Вершина %d концевая\n", i+1);
        if (sizeStr >= n-1) printf("Вершина %d доминирующая\n", i+1);
    }

    m = sizeGraf;
    GI = (int **)malloc(m*sizeof(int*));
    for (int i=0; i<m; i++)
        GI[i] = (int*)malloc(n*sizeof(int));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            GI[j][i] = 0;
        }
    }

    int num = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            if (G[i][j]==1) {
                if (i==j)
                    GI[num][i] = 2;
                else {
                    GI[num][i] = 1;
                    GI[num][j] = 1;
                }
                num++;
            }
        }
    }

    sizeGraf = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (GI[j][i]>0) sizeGraf = sizeGraf + GI[j][i]; 
        }
    }
    sizeGraf = sizeGraf/2;

    printf("\n");

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ",GI[j][i]);
        }
        printf("\n");
    }
    printf("Размер графа равен %d \n", sizeGraf);

    for (int i=0; i<n; i++){
        int sizeStr = 0;
        bool petlya = false;
        for (int j = 0; j<m; j++){
            if (GI[j][i] == 2) petlya == true;
            if (GI[j][i] == 1) sizeStr = sizeStr + 1;
        }
        if (sizeStr == 0) printf("Вершина %d изолированная\n", i+1);//комментарии для теста
        if (sizeStr == 1) printf("Вершина %d концевая\n", i+1);
        if (sizeStr >= n-1) printf("Вершина %d доминирующая\n", i+1);
    }

    return 0;
}