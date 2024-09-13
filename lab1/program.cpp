#include <iostream>
#include <stdlib.h>
#include<string.h>

int   main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i;
    bool search = false;
	struct student
	{
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[4];

	for(i=0;i<3;i++)
	{
		printf("Введите фамилию студента\n"); scanf ("%20s",stud[i].famil);
	}
	for(i=0;i<3;i++)
	{
		printf("Введите имя студента %s\n",stud[i].famil); scanf ("%20s",stud[i].name);
	}
	for(i=0;i<3;i++)
	{
		printf("Введите название факультета студента %s %s\n",stud[i].famil,stud[i].name); scanf ("%20s",stud[i].facult);
	}
	for(i=0;i<3;i++)
	{
		printf("Введите номер зачётной книжки студента %s %s\n",stud[i].famil,stud[i].name); scanf ("%d",&stud[i].Nomzach);
	}

	for(i=0;i<3;i++)
		{
			printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n",stud[i].famil,stud[i].name,
					stud[i].facult,stud[i].Nomzach);
		}
    
    printf("Введите фамилию искомого студента\n"); scanf("%20s",stud[4].famil);
    printf("Введите имя искомого студента %s\n",stud[4].famil); scanf("%20s",stud[4].name);
    
    for (int i = 0; i < 3; i++)
    {
        if ((!strcmp(stud[i].famil,stud[4].famil)) and (!strcmp(stud[i].name,stud[4].name)))
        {
            printf("Студент %s %s найден!", stud[i].famil, stud[i].name);
            search = true;
        }
    }
    
    if (search == false) {
        printf("Такой студент не найден!");
    }

}
