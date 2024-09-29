#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

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
	if (*s == 0)
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
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
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


int main(void) {
    bool exitApp = false;

    while(exitApp!=true) {
        int state = 0;
        printf("1: добавить элемент\n2: удалить элемент\n3: найти элемент\n4: отобразить очередь\n5: выйти");
        printf("\nВыберите действие: ");
        scanf("%d",&state);
        switch (state){
        case 1:
            spstore();
            printf("\n");
            break;
        case 2:
            char delData[256];
            printf("Введите значение удаляемого элемента: ");
            scanf("%s", &delData);
            del(delData);
            printf("\n");
            break;
        case 3:
            char findData[256];
            printf("Введите данные элемента для его поиска: ");
            scanf("%s", &findData);
            find(findData);
            printf("\n");
            break;
        case 4:
            printf("\n");
            review(head);
            printf("\n\n");
            break;
        case 5:
            exitApp = true;
            break;
        default:
            printf("Введена неверная команда\n\n");
            break;
        }
    };

return 0;
}