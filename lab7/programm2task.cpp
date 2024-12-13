#include <stdio.h>
#include <random>
#include <time.h>
#include <stack>

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

void DFS(int **G, int s,int size, int *vis){
    std::stack<int> q;
    q.push(s);
    bool flag = true;
    while (!q.empty()) {
        if (flag) printf("%d ", q.top());
        vis[q.top()] = 1;
        for (int i=0; i<size; i++) {
            flag = false;
            if (G[q.top()][i]==1 && vis[i]==0) {
                q.push(i);
                flag = true;
                break;
            }
        }
        if (!flag) q.pop();
    }
}

int main() {
    srand(time(NULL));
    int sizeG1;
    int Ivis;
    int **G1;
    int *vis = NULL;
    printf("Введите количество вершин графа: ");
    scanf("%d", &sizeG1);
    G1 = createG(sizeG1);
    printG(G1, sizeG1);
    printf("\n");
    vis = (int*)malloc(sizeG1*sizeof(int));
    for (int i=0; i<sizeG1; i++)
        vis[i] = 0;
    DFS(G1,0,sizeG1,vis);
    return 0;
}