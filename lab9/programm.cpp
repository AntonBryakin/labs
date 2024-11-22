#include <stdio.h>
#include <random>
#include <time.h>
#include  <queue>
using namespace std;

int **createG(int size) {
    int **G;
    G = (int **)malloc(size*sizeof(int *));
    for (int i = 0; i < size; i++){
        G[i] = (int*)malloc(size*sizeof(int));
    }
    for (int i=0; i<size; i++){
        for (int j=i; j<size; j++){
            G[i][j] = (rand()%2);
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

void BFSD(int **G, int s,int size, int *dist){
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()){
        s = q.front();
        printf("%d ", s);
        q.pop();
        for (int i=0; i<size; i++) {
            if (G[s][i]==1 and dist[i]==-1) {
                q.push(i);
                dist[i]=dist[s]+1;
            }
        }
    }
    return;

}

int main() {
    srand(time(NULL));
    int size;
    int v;
    int **G;
    int *dist = NULL;
    printf("Введите количество вершин графа: ");
    scanf("%d", &size);
    G = createG(size);
    printG(G, size);
    printf("\n");
    printf("Введите номер вершины из которой будет производиться поиск: ");
    scanf("%d", &v);
    dist = (int*)malloc(size*sizeof(int));
    for (int i=0;i<size;i++) {
        dist[i] = -1;
    }
    BFSD(G,0,size,dist);
    printf("\n\n");
    for (int i=0;i<size;i++) {
        printf("v: %d ",i);
        printf("dist: %d ",dist[i]);
        printf("\n");
    }
    return 0;
}