#include <stdio.h>
#include <random>
#include <time.h>
#include <stack>

struct Vertex {
    int data;
    struct Vertex *next;
};

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

void DFSR(int** G, int s, int size, int *vis){
  vis[s] = 1;
  printf("%d ", s);
  for (int i = 0; i < size; i++){
    if (G[s][i] == 1 && vis[i] == 0){
      DFSR(G, i, size, vis);
      printf("\n");
    }
  }
}

struct Vertex *get_struct(int Dat){
	struct Vertex *v = NULL;

	if ((v = (Vertex*)malloc(sizeof(struct Vertex))) == NULL){
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	v->data = Dat;
	v->next = NULL;

	return v;
}

struct Vertex *createList(int **G, int size){
    struct Vertex *GS = new struct Vertex[size];
    for (int i=0; i<size; i++){
        GS[i].data = i;
        GS[i].next = NULL;
        for (int j=0; j<size; j++){
            if(G[i][j]==1) {
                struct Vertex *newVertex = NULL;
                newVertex = get_struct(j);
                if (GS[i].next != NULL) {
                    struct Vertex *temp = GS[i].next;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newVertex;
                } else {
                    GS[i].next = newVertex;
                }
            }
        }
    }
    return GS;
}

int printGS(struct Vertex *GS, int size) {
    for (int i=0; i<size; i++){
        printf("%d ",GS[i].data);
        if (GS[i].next != NULL) {
            struct Vertex *temp = GS[i].next;
            while (temp->next != NULL) {
                printf("%d ",temp->data);
                temp = temp->next;
            }
            printf("%d ",temp->data);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

void DFS(struct Vertex *GS, int s,int size, int *vis){
    vis[s] = 1;
    printf("%d ", s);
    if (GS[s].next != NULL) {
        struct Vertex *temp = GS[s].next;
        while (temp->next != NULL) {
            if (vis[temp->data] == 0) DFS(GS, temp->data,size,vis);
            temp = temp->next;
        }
        if (vis[temp->data] == 0) DFS(GS, temp->data,size,vis);
        printf("\n");
    }
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

void DFSС(int **G, int s,int size, int *vis){
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
    int **G1;
    struct Vertex *GS;
    int *vis = NULL;
    printf("Введите количество вершин графа: ");
    scanf("%d", &sizeG1);
    G1 = createG(sizeG1);
    GS = createList(G1,sizeG1);
    printf("\n");
    printG(G1, sizeG1);
    printf("\n");
    vis = (int*)malloc(sizeG1*sizeof(int));
    for (int i=0; i<sizeG1; i++)
        vis[i] = 0;
    DFSR(G1,0,sizeG1,vis);
    printf("\n");
    for (int i=0; i<sizeG1; i++)
        vis[i] = 0;
    DFSС(G1,0,sizeG1,vis);
    printf("\n\n");
    printGS(GS, sizeG1);
    printf("\n");
    for (int i=0; i<sizeG1; i++)
        vis[i] = 0;
    DFS(GS,0,sizeG1,vis);
    return 0;
}