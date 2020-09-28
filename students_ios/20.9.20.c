#include<stdio.h>
#include<malloc.h>
void OutputStudent(struct student*);
struct student
{
	int age;
	float mark;
	char name[100];
};
int main()2
{
	//int a[0][3] = {0};

	int len;
	int i;
	struct student *value;
	printf("input student number \n");
	scanf_s("%d", &len);

	value = (struct student*)malloc(sizeof(struct student)*len);
	for (i = 0; i < len;i++)
	{
		
		printf("input student age in %d\n",i+1);
		scanf_s("age = %d",&value[i].age);
		printf("input student mark in  %d\n", i);
		scanf_s("mark = %f",&value[i].mark);
	}
	//OutputStudent(value);
	return 0;

}
void OutputStudent(struct student *p)
{
	printf("value[0].age = %d\n",p[0].age);
	printf("value[1].age = %d\n",p[1].age);
}
//问自己哪里错了？？
