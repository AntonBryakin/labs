#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root;

struct Node *CreateTree(struct Node *root, struct Node *r, int data) {
	if (r == NULL) {
		r = (struct Node *)malloc(sizeof(struct Node));
		if (r == NULL) {
			printf("Ошибка выделения памяти");
			exit(0);
		}
		
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data) root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
    else
		CreateTree(r, r->right, data);

	return root;
}

struct Node *find (struct Node *root, int data) {
    
    if (root->data == data) return root;

    if (root->data > data && root->right != NULL) root = find(root->right, data);
    else if (root->left != NULL) root = find(root->left, data);

    return root;
}

int count(struct Node *root, int data, int cnt) {
    
    if (root->data == data) cnt++;

    if (root->data >= data && root->right != NULL) cnt = count(root->right, data, cnt);
    else if (root->left != NULL) cnt = count(root->left, data, cnt);

    return cnt;
}

void print_tree(struct Node *r, int l)
{
	if (r == NULL){
		return;
	}
	
	print_tree(r->right, l + 1);
	for(int i = 0; i < l; i++) {
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left,  l+1);
}

int main() {

    bool exitApp = false;
    root = NULL;

    while(exitApp!=true) {
        int state = 0;
        int D;
        printf("1: добавить элемент\n2: найти элемент\n3: нарисовать текущее дерево\n4: посчитать повторение элементов\n5: выйти");
        printf("\nВыберите действие: ");
        scanf("%d",&state);
        switch (state){
        case 1:
            printf("\n");
            printf("Введите число: ");
		    scanf_s("%d", &D);
            printf("\n");
            root = CreateTree(root, root, D);
            printf("\n");
            break;
        case 2: {
            struct Node *r = NULL;
            int r_data;
			printf("\nВведите данные искомого элемента: ");
            scanf("%d",&r_data);
            // printf("%d",r_data);
            r = find(root, r_data);
            printf("\n");
            if (r != NULL) printf("Элемент %d найден", r->data);
            else printf("Элемент не найден");
            printf("\n\n");
            break;
        }
        case 3:
            printf("\n");
            print_tree(root,0);
            printf("\n");
            break;
        case 4: {
            int cnt_r = 0;
            int r_data;
			printf("\nВведите данные искомого элемента: ");
            scanf("%d",&r_data);
            printf("%d",r_data);
            cnt_r = count(root, r_data, 0);
            printf("\n");
            if (cnt_r != 0) printf("Найдено %d элемента", cnt_r);
            else printf("Элемент не найден");
            printf("\n\n");
            break;
        }
        case 5:
            exitApp = true;
            break;
        default:
            printf("Введена неверная команда\n\n");
            break;
        };
    };

return 0;
}