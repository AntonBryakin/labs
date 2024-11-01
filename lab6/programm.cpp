#include <stdio.h>
#include <random>
#include <time.h>

int **createG(int size) {
    int **G;
    G = (int **)malloc(size*sizeof(int *));
    for (int i = 0; i < size; i++){
        G[i] = (int*)malloc(size*sizeof(int));
    }
    for (int i=0; i<size; i++){
        for (int j=i; j<size; j++){
            G[i][j] = rand()%2;
            if (i == j) G[i][j] = 0;
            G[j][i] = G[i][j];
        }
    }
    return G;
}

int printG(int **G ,int size) {
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            printf("%d ",G[i][j]);
        }
    printf("\n");
    }
    return 0;
}

int **delV(int **G, int size, int v) {
    int **Gtemp = createG(size-1);

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if((i < v) && (j < v)) Gtemp[i][j] = G[i][j];
            if((i > v) && (j > v)) Gtemp[i-1][j-1] = G[i][j];
            if((i > v) && (j < v)) Gtemp[i-1][j] = G[i][j];
            if((i < v) && (j > v)) Gtemp[i][j-1] = G[i][j];
        }
    }
    
    return Gtemp;
}

void unionV(int **G, int size, int v1, int v2){
    
    for (int i=0; i<size; i++){
        if (G[v2][i] == 1) {
            G[v1][i] = G[v2][i];
            G[i][v1] = G[i][v2];
        }
    }
    if(G[v1][v2] == 1){
        G[v1][v1] = 1;
    }

    G = delV(G,size,v2);
    return;
}

int cutV(int **G, int size, int v1, int v2){

    for (int i=0; i<size; i++){
        if (G[v2][i] == 1) {
            G[v1][i] = G[v2][i];
            G[i][v1] = G[i][v2];
        }
    }
    if(G[v1][v2] == 1){
        G[v1][v1] = 0;
    }

    G = delV(G,size,v2);
    return 0;
}

int **rasV(int **G, int size, int v) {
    
    int **Gtemp = createG(size+1);

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            Gtemp[i][j] = G[i][j];
        }
    }

    printG(Gtemp, size+1);

    for (int i = 0; i < size; i++) {
        Gtemp[i][size] = G[v][i];
        Gtemp[size][i] = G[v][i];
    }
    Gtemp[size][size] = 0;
    
    return Gtemp;
}

int main() {
    srand(time(NULL));
    
    int nG1 = 3, nG2 = 5, v1, v2;
    printf("Введите количество вершин G1\n");
    scanf("%d", &nG1);
    printf("Введите количество вершин G2\n");
    scanf("%d", &nG2);

    int **G1 = createG(nG1);
    int **G2 = createG(nG2);


    printf("Граф G1 \n");
    printG(G1, nG1);
    printf("\n");

    printf("Граф G2 \n");
    printG(G2, nG2);
    printf("\n");


    printf("Введите номер первой вершины \n");
    scanf("%d", &v1);
    printf("Введите номер второй вершины \n");
    scanf("%d", &v2);

    unionV(G1,nG1,v1-1,v2-1);
    printf("Граф G1 \n");
    nG1--;
    printG(G1, nG1);
    printf("\n");


    printf("Введите номер первой вершины \n");
    scanf("%d", &v1);
    printf("Введите номер второй вершины \n");
    scanf("%d", &v2);

    if (G2[v1-1][v2-1] == 0) {
        printf("Ребро между вершинами не существует");
    } else {
        cutV(G2,nG2,v1-1,v2-1);
        printf("Граф G2 \n");
        nG2--;
        printG(G2, nG2);
    }
    printf("\n");
    printf("\n");


    printf("Введите номер расщепляемой вершины \n");
    scanf("%d", &v1);
    
    G2 = rasV(G2,nG2,v1-1);
    printf("Граф G2 \n");
    nG2++;
    printG(G2, nG2);

    return 0;
}