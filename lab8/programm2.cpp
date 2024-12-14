#include <stdio.h>
#include <random>
#include <time.h>
#include  <queue>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Vertex {
    int data;
    struct Vertex *next;
};


struct node *head = NULL, *last = NULL;

struct node
{
	char inf[256];  // полезная информация
	struct node *next; // ссылка на следующий элемент 
};

struct node *get_struct(void)
{
	struct node *p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL)  // выделяем память под новый элемент списка
	{
		printf("Ошибка при распределении памяти\n");
		exit(1);
	}

	printf("Введите данные: \n");   // вводим данные
	scanf("%s", s);
	if ((*s == 0))
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;

	return p;		// возвращаем указатель на созданный элемент
}

void spstore(void)
{
	struct node *p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть
	{
		last->next = p;
		last = p;
	}
	return;
}

void review(struct node *first)
{
	struct node *struc = first;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		printf("%s -> ", struc->inf);
		struc = struc->next;
	}
	return;
}

struct node *find(char *name)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("Список пуст\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
            printf("Такой элемент был найден\n");
			return struc;
		}
		struc = struc->next;
	}
	printf("Элемент не найден\n");
	return NULL;
}


void del(char *name)
{
	struct node *struc = head;// указатель, проходящий по списку установлен на начало списка
	struct node *prev;// указатель на предшествующий удаляемому элемент
	int flag = 0;// индикатор отсутствия удаляемого элемента в списке

	if (head == NULL)// если голова списка равна NULL, то список пуст
	{
		printf("Список пуст\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0)// если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next;// установливаем голову на следующий элемент
		free(struc);// удаляем первый элемент
		struc = head;// устанавливаем указатель для продолжения поиска
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{
			flag = 1;// выставляем индикатор
			if (struc->next)// если найденный элемент не последний в списке
			{
				prev->next = struc->next; // меняем указатели
				free(struc);		    // удаляем  элемент
				struc = prev->next; // устанавливаем указатель для продолжения поиска
			}
			else// если найденный элемент последний в списке
			{
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc);// удаляем  элемент
				return;
			}
		}
		else// если не нашли, то
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}

	if (flag == 0)// если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}
}



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
            G[i][j] = rand()%2;
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

//поиск в ширину для списков смежности
void BFSS(struct Vertex *GS, int s,int size, int *vis){
    queue<int> q;
    int beg = GS[s].data;
    q.push(beg);
    vis[beg] = 1;

    while (!q.empty()){
        s = q.front();
        printf("%d ", s);
        q.pop();
        struct Vertex *temp = GS[s].next;
        while (temp->next != NULL){
            if (vis[temp->data]!=1) {
                q.push(temp->data);
                vis[temp->data]=1;
            }
            temp = temp->next;
        }
        if (vis[temp->data]!=1) {
            q.push(temp->data);
            vis[temp->data]=1;
        }
    }
    return;

}

//поиск в ширину для матрицы смежности
void BFS(int **G, int s,int size, int *vis){
    spstore(to_string(s));
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
    srand(time(NULL));
    int sizeG1,**G1,*vis = NULL; //объявление размера графа, двумерного массива, и вектора посещённых вершин
    struct Vertex *GS;

    printf("Введите количество вершин графа: "); //спрашиваем пользователя про количество вершин
    scanf("%d", &sizeG1); //считываем введённые данные в переменную
    
    G1 = createG(sizeG1); //создаём матрицу смежности
    GS = createList(G1,sizeG1);//создаем списки смежности
    printG(G1, sizeG1); //выводим матрицу смежности
    printf("-------------------\n"); //разделитель между выводом графа
    printGS(GS, sizeG1); //выводим списки смежности
    
    printf("-------------------\n"); //разделитель между списком смежности и выводом результата обхода по матрице смежности
    printf("Обход по матрице смежности\n");
    vis = (int*)malloc(sizeG1*sizeof(int)); //выделяем память под вектор посещённых вершин
    BFS(G1,0,sizeG1,vis); //поиск в ширину в матрице смежности
    for (int i=0; i<sizeG1; i++)
        vis[i] = 0; //заполняем вектор посещённых вершин нулями
    printf("\n-------------------\n"); //разделитель между обходом по матрице и выводом результата обхода по спискам смежности
    printf("Обход по спискам смежности\n");
    BFSS(GS,0,sizeG1,vis);//поиск в ширину для списков
    return 0;
}