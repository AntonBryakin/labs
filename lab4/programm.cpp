#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *root = NULL;

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

    if (root->data > data && root->right != NULL) find(root->right, data);
    else if (root->left != NULL) find(root->left, data);
    else return NULL;
}

int count (struct Node *root, int data, int cnt) {
    
    if (root->data == data) cnt++;

    if (root->data >= data && root->right != NULL) cnt = count(root->right, data, cnt);
    else if (root->left != NULL) cnt = count(root->left, data, cnt);
    else return cnt;
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

    while(exitApp!=true) {
        int state = 0;
        int D;
        printf("1: добавить элемент\n2: найти элемент\n3: нарисовать текущее дерево\n4: выйти");
        printf("\nВыберите действие: ");
        scanf("%d",&state);
        switch (state){
        case 1:
            printf("\n");
            printf("Введите число: ");
		    scanf_s("%d", &D);
            printf("\n");
            root = CreateTree(root, root, D);
            printf("\n\n");
            break;
        case 2:
			char n[256];
			printf("\nВведите данные искомого элемента: ");
			scanf("%s",n);
            int r = 0;
            r = find(root,D)->data;
            printf("\n");
            if (r != 0) printf("Элемент %d найден", &r);
            else printf("Элемент не найден");
            printf("\n\n");
            break;
        case 3:
            print_tree(root,0);
            break;
        case 4:
            exitApp = true;
            break;
        default:
            printf("Введена неверная команда\n\n");
            break;
        }
    };

return 0;
}