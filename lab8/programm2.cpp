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

// void DFS(int **G, int s,int size, int *vis){
//     vis[s] = 1;
//     printf("%d ", s);
//     for (int i=0; i<size; i++){
//         if (G[s][i]==1 && vis[s]==0) {
//             DFS(G, i, size, vis);
//         }
//     }
// }

void BFS(int **G, int s,int size, int *vis){
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()){
        s = q.front();
        printf("%d ", s);
        q.pop();
        for (int i=0; i<size; i++) {
            if (G[s][i]==1 and vis[i]!=1) {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    return;

}

int main() {
    int sizeG1;
    int **G1;
    int *vis = NULL;
    printf("Введите количество вершин графа: ");
    scanf("%d", &sizeG1);
    G1 = createG(sizeG1);
    printG(G1, sizeG1);
    printf("\n");
    vis = (int*)malloc(sizeG1*sizeof(int));
    BFS(G1,0,sizeG1,vis);
    return 0;
}