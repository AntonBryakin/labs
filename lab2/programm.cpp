#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int *items, int count) {
    int i, j, gap, k;
    int x, a[5];

    a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

    for(k=0; k < 5; k++) {
        gap = a[k];
        for(i=gap; i < count; ++i) {
        x = items[i];
        for(j=i-gap; (x < items[j]) && (j >= 0); j=j-gap)
            items[j+gap] = items[j];
        items[j+gap] = x;
        }
    }
}

void qs(int *items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
  int i, j;
  int x, y;

  i = left; j = right;

  /* выбор компаранда */
  x = items[(left+right)/2];
  
  do {
    while((items[i] < x) && (i < right)) i++;
    while((x < items[j]) && (j > left)) j--;

    if(i <= j) {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(items, left, j);
  if(i < right) qs(items, i, right);
}

void arr_rand(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = rand()%100000+1;
    }
}
void arr_up(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = i;
    }
}
void arr_down(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        arr[i] = 100000 - i;
    }
}
void arr_upDown(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        if (i<50000)
            arr[i] = i;
        else 
            arr[i] = 100000-i;
    }
}

void view_arr(int *arr){
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int a[100000];

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

    int starttime = clock();
    arr_rand(a); //сортировка шелла на рандомном массиве
    shell(a,100000);
    float diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения сортировки Шелла на рандомном массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_up(a);//сортировка шелла на возрастающем массиве
    shell(a,100000);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения сортировки Шелла на возрастающем массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_down(a);//сортировка шелла на убывающем массиве
    shell(a,100000);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения сортировки Шелла на убывающем массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_upDown(a);//сортировка шелла на возрастающем и убывающем массиве
    shell(a,100000);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения сортировки Шелла на возрастающем и убывающем равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_rand(a); //данная быстрая сортировка на рандомном массиве
    qs(a,0,99999);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения быстрой сортировки на рандомном массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_up(a);//данная быстрая сортировка на возрастающем массиве
    qs(a,0,99999);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения быстрой сортировки на возрастающем массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_down(a);//данная быстрая сортировка на убывающем массиве
    qs(a,0,99999);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения быстрой сортировки на убывающем массиве равно: %f сек.\n", diff);
    view_arr(a);

    // starttime = clock();
    // arr_upDown(a);//данная быстрая сортировка на возрастающем и убывающем массиве
    // qs(a,0,99999);
    // diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    // printf("Время выполнения быстрой сортировки на возрастающем и убывающем равно: %f сек.\n", diff);
    // view_arr(a);

    starttime = clock();
    arr_rand(a); //данная быстрая сортировка на рандомном массиве
    qsort(a,100000,sizeof(int),NULL);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения встроенной быстрой сортировки на рандомном массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_up(a);//данная быстрая сортировка на возрастающем массиве
    qsort(a,100000,sizeof(int),NULL);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения встроенной быстрой сортировки на возрастающем массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_down(a);//данная быстрая сортировка на убывающем массиве
    qsort(a,100000,sizeof(int),NULL);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения встроенной быстрой сортировки на убывающем массиве равно: %f сек.\n", diff);
    view_arr(a);

    starttime = clock();
    arr_upDown(a);//данная быстрая сортировка на возрастающем и убывающем массиве
    qsort(a,100000,sizeof(int),NULL);
    diff = ((clock()) - starttime)/float(CLOCKS_PER_SEC);
    printf("Время выполнения встроенной быстрой сортировки на возрастающем и убывающем равно: %f сек.\n", diff);
    view_arr(a);

	return(0);
}
