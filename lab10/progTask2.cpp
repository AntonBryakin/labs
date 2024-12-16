#include <stdio.h>
#include <random>
#include <time.h>
#include  <queue>
using namespace std;

int **createG(int sost, int size) {
    int **G;
    G = (int **)malloc(size*sizeof(int *));
    for (int i = 0; i < size; i++){
        G[i] = (int*)malloc(size*sizeof(int));
    }
    switch (sost)
    {
    case 0: //взвешенный неориентированный
        for (int i=0; i<size; i++){
            for (int j=i; j<size; j++){
                G[i][j] = (rand()%2);
                if (G[i][j]==1) G[i][j]=G[i][j]*rand()%30;
                if (i == j) G[i][j] = 0;
                G[j][i] = G[i][j];
            }
        }
        break;
    case 1: //взвешенный ориентированный
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                G[i][j] = (rand()%2);
                if (G[i][j]==1) G[i][j]=G[i][j]*rand()%30;
                if (i == j) G[i][j] = 0;
            }
        }
        break;
    case 2: //невзвешенный неориентированный
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                G[i][j] = (rand()%2);
                if (i == j) G[i][j] = 0;
            }
        }
        break;
    case 3: //невзвешенный ориентированный
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                G[i][j] = (rand()%2);
                if (i == j) G[i][j] = 0;
                G[j][i] = G[i][j];
            }
        }
        break;
    default:
        break;
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
        q.pop();

        for (int i=0; i<size; i++) {
            if (G[s][i]>0 and dist[i]==INT_MAX) {
                q.push(i);
                dist[i]=dist[s]+G[s][i];
            }
        }
    }
    return;

}

int min_el(int *vec, int size){
    int min_element = INT_MAX;
    for (int i=0;i<size;i++){
        if (min_element>vec[i]) min_element = vec[i];
    }
    return min_element;
}

int max_el(int *vec, int size){
    int max_element = INT_MIN;
    for (int i=0;i<size;i++){
        if ((max_element<vec[i]) & (vec[i]!=INT_MAX)) max_element = vec[i];
    }
    return max_element;
}

void printInformation(int **G,int size, int sost){
    int *excentrs;
    int *dist;
    switch (sost)
    {
    case 0:
        printf("Взвешенный, неориентированный граф:\n");
        break;
    case 1:
        printf("Взвешенный, ориентированный граф:\n");
        break;
    case 2:
        printf("Невзвешенный, ориентированный граф:\n");
        break;
    case 3:
        printf("Невзвешенный, неориентированный граф:\n");
        break;
    default:
        break;
    }
    printG(G,size);
    printf("------------------------------\nМатрица достижимости для данного графа:\n");

    dist = (int *)malloc(size*sizeof(int));//выделяем память под вектор расстояний
    excentrs = (int *)malloc(size*sizeof(int));//выделяем память под вектор значений эксцентриситет

    for (int k=0;k<size;k++){
        for (int i=0;i<size;i++) { //каждый раз заполняем вектор dist
            dist[i] = INT_MAX; //кладём в него максимальное значение
        }
        BFSD(G, k, size, dist); //производим поиск расстояний от каждой из вершин
        excentrs[k] = max_el(dist,size); //ищем эксцентриситет вершины
        for (int i=0;i<size;i++) { //вывод вектора с расстояниями от вершины
            if (dist[i]==INT_MAX) printf("oo ");
            else printf("%d ", dist[i]);
        }
        printf("\n");
    }
    printf("------------------------------\n");
    int diametr = max_el(excentrs,size);
    int radius = min_el(excentrs,size);
    printf("Диаметр графа равен: %d\n", diametr);
    printf("Радиус графа равен: %d\n", radius);
    printf("------------------------------\n");
    for(int i=0;i<size;i++){
        if (excentrs[i]==diametr) printf("Вершина %d переферийная.\n", i);
        if (excentrs[i]==radius) printf("Вершина %d центральная.\n", i);
    }
    printf("------------------------------\n");
}

int main() {
    srand(time(NULL));
    int **G, *dist, size, **GO, *excentrs;

    printf("Введите количество вершин графа: ");//пользователь вводит размер
    scanf("%d", &size);

    G = createG(3, size);//генерируем НЕнаправленный граф
    printInformation(G, size, 3);

    return 0;
}