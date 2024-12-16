#include <stdio.h>
#include <random>
#include <time.h>
#include  <queue>
#include <stack>

using namespace std;

struct Vertex {
    int data;
    struct Vertex *next;
};

//создает вершину, возвращает указатель на неё, принимает целое число - данные
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

//функция создания списков смежности из матрицы смежности и её размера, возвращает указатель на массив структур - вершин
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

//функция вывода списков смежности
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
    return 0;
}

//функция создания графа в виде матрицы смежности
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

//вывод матрицы смежности
int printG(int **G ,int size) {
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            printf("%d ",G[i][j]);
        }
    printf("\n");
    }
    return 0;
}

//поиск расстояний от вершины, с помощью обхода в ширину
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

//поиск в ширину для списков смежности
void BFSDS(struct Vertex *GS, int s,int size, int *dist){
    queue<int> q;
    int beg = GS[s].data;
    q.push(beg);
    dist[beg] = 0;

    while (!q.empty()){
        s = q.front();
        printf("%d ", s);
        q.pop();
        struct Vertex *temp = GS[s].next;
        while (temp->next != NULL){
            if (dist[temp->data]==-1) {
                q.push(temp->data);
                dist[temp->data]=dist[s]+1;
            }
            temp = temp->next;
        }
        if (dist[temp->data]==-1) {
            q.push(temp->data);
            dist[temp->data]=dist[s]+1;
        }
    }
    return;
}

//нахождение расстояний поиском в глубину
void DFSD(int **G, int s, int size, int *vis, int *dist){
	stack<int> st;
	st.push(s);
	vis[s] = 1;
	dist[s] = 0;

	while (!st.empty()){
		int v = st.top();
		st.pop();
		printf("%d ", v);

		for (int i = size - 1; i >= 0; i--){
			if (G[v][i] == 1 && vis[i] == 0){
				st.push(i);
				vis[i] = 1;
				dist[i] = dist[v] + 1;
			}
		}
	}
}

//нахождение расстояний поиском в глубину по спискам смежности
void DFSDC(struct Vertex *GS, int s, int size, int *dist, int depth){
    struct Vertex *temp = GS[s].next;
    if((dist[s] == -1) || (dist[s]>depth)){
        printf("%d ",s);
        dist[s] = depth;
        depth++;
        while(temp!=NULL){
            DFSDC(GS, GS[temp->data].data, size, dist, depth);
            temp = temp->next;
        }
    }
}

int main() {
    srand(time(NULL));
    int size, v, **G, *dist = NULL, *vis;
    struct Vertex *GS;

    printf("Введите количество вершин графа: ");
    scanf("%d", &size);//считываем размер гарфа
    G = createG(size); //создаём матрицу смежности
    printG(G, size); //выводим матрицу смежности
    printf("-------------------\n"); //разделитель после матрицы смежности
    GS = createList(G,size);//создаем списки смежности
    printGS(GS, size); //выводим списки смежности
    printf("-------------------\n"); //разделитель между списком смежности и выводом результата обхода по матрице смежности

    printf("Введите номер вершины из которой будет производиться поиск: ");
    scanf("%d", &v);
    printf("-------------------\n"); //разделитель между выводом вопроса для пользователя и результатом поиска расстояний
    dist = (int*)malloc(size*sizeof(int)); //выделяем память под вектор расстояний
    vis = (int*)malloc(size*sizeof(int)); //выделяем память под вектор посещённых вершин
    for (int i=0;i<size;i++) {
        dist[i] = -1; //заполняем его -1
    }
    int startTime = clock();
    BFSD(G,v,size,dist); //производим поиск расстояний
    printf("\nВремя работы этого алгоритма: %f",(clock()-startTime)/float(CLOCKS_PER_SEC));
    printf("\n-------------------\nПоиск расстояний по матрице смежности:\n"); 
    for (int i=0;i<size;i++) { //вывод вектора с расстояниями от вершины
        printf("v: %d ",i);
        printf("dist: %d ",dist[i]);
        printf("\n");
    }
    for (int i=0;i<size;i++) { //заполнение вектор -1, для поиска по спискам смежности
        dist[i] = -1;
    }
    printf("-------------------\n");
    BFSDS(GS,v,size,dist); 
    printf("\n-------------------\nПоиск расстояний по спискам смежности:\n"); 
    for (int i=0;i<size;i++) { //вывод вектора с расстояниями от вершины
        printf("v: %d ",i);
        printf("dist: %d ",dist[i]);
        printf("\n");
    }
    for (int i=0;i<size;i++) { //заполнение вектор -1, для поиска по спискам смежности
        vis[i] = 0;
        dist[i] = -1;
    }
    printf("-------------------\n");
    startTime = clock();
    DFSD(G,v,size,vis,dist); //поиск в глубину - нахождение расстояний от вершины
    printf("\nВремя работы этого алгоритма: %f",(clock()-startTime)/float(CLOCKS_PER_SEC));
    printf("\n-------------------\nПоиск расстояний обходом в глубину:\n"); 
    for (int i=0;i<size;i++) { //вывод вектора с расстояниями от вершины
        printf("v: %d ",i);
        printf("dist: %d ",dist[i]);
        printf("\n");
    }

    for (int i=0;i<size;i++) { //заполнение вектор -1, для поиска по спискам смежности
        dist[i] = -1;
    }
    printf("-------------------\n");
    DFSDC(GS,v,size,dist,0); //поиск в глубину - нахождение расстояний от вершины по спискам смежности
    printf("\n-------------------\nПоиск расстояний обходом в глубину по спискам смежности:\n"); 
    for (int i=0;i<size;i++) { //вывод вектора с расстояниями от вершины
        printf("v: %d ",i);
        printf("dist: %d ",dist[i]);
        printf("\n");
    }
    return 0;
}