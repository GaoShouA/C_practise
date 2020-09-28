// An highlighted block
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student* recreate();
struct student* create(struct student* head);
struct student* addcreate(struct student* head);
int find_std(struct student* p);
int find_num(struct student* head);
int find_name(struct student* head);
struct student* delete_std(struct student* head);
struct student* delete_num(struct student* head);
struct student* delete_name(struct student* head);
int update_std(struct student* head);
void sort_std(struct student* head);
int show(struct student* p);
struct student {
	char name[20];
	int age;
	char num[20];
	int chinese, english, math;
	double average;
	struct student* next;
};
int main() {
	int chos;
	struct student* head = NULL;
	while (1) {
		printf("-------------------------\n");
		printf("--------1.添加学生-------\n");
		printf("--------2.查询学生-------\n");
		printf("--------3.删除学生-------\n");
		printf("------4.修改学生信息-----\n");
		printf("-----5.显示学生信息------\n");
		printf("--------6.排序-----------\n");
		printf("--------7.退出-----------\n");
		printf("-------------------------\n");
		printf("请输入编号：\n");
		scanf("%d", &chos);
		switch (chos) {
		case 1:head = create(head); break;
		case 2:find_std(head); break;
		case 3:head = delete_std(head); break;
		case 4:update_std(head); break;
		case 5:show(head); break;
		case 6:sort_std(head); break;
		case 7:exit(0);
		default: printf("输入错误！请重新输入！");
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//添加学生
struct student* create(struct student* head) {
	int chos;
	printf("--------1.重新添加学生-------\n");
	printf("------------2.补录学生-------\n");
	printf("------------3.退出-----------\n");
	printf("请输入：");
	scanf("%d", &chos);
	switch (chos) {
	case 1:head = recreate(); break;
	case 2:head = addcreate(head); break;
	case 3:return NULL; break;
	default: printf("输入错误！请重新输入！"); return NULL;
	}
	return head;
}
//重新增加学生信息
struct student* recreate() {
	int n, age, chinese, english, math, i;
	double average;
	struct student* p, * head, * tail;
	head = tail = NULL;
	printf("输入要增加学生人数！\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		if ((p = (struct student*)malloc(sizeof(struct student))) == NULL)
		{
			printf("\t\t\t\t获取内存失败，请重试！\n");
			return NULL;
		}
		printf("-----请输入第%d个学生信息-----\n", i + 1);
		printf("请输入学生名字：\n");
		scanf("%s", p->name);
		printf("请输入学生年龄：\n");
		scanf("%d", &age);
		p->age = age;
		printf("请输入学生学号：\n");
		scanf("%s", p->num);
		printf("请输入学生语文成绩：\n");
		scanf("%d", &chinese);
		printf("请输入学生数学成绩：\n");
		scanf("%d", &math);
		printf("请输入学生英语成绩：\n");
		scanf("%d", &english);
		p->chinese = chinese;
		p->english = english;
		p->math = math;
		average = (chinese + math + english) / 3.0;
		p->average = average;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	return head;
}
//补录学生
struct student* addcreate(struct student* tail) {
	int n, age, chinese, english, math, i;
	double average;
	struct student* head, * p;
	if (tail == NULL)
	{
		head = recreate();
		return head;
	}
	head = tail;
	while (1)
	{
		if (tail->next == NULL)
			break;
		tail = tail->next;
	}
	printf("输入要增加学生人数！\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		if ((p = (struct student*)malloc(sizeof(struct student))) == NULL)
		{
			printf("\t\t\t\t获取内存失败，请重试！\n");
			return NULL;
		}
		printf("请输入学生名字：\n");
		scanf("%s", p->name);
		printf("请输入学生年龄：\n");
		scanf("%d", &age);
		p->age = age;
		printf("请输入学生学号：\n");
		scanf("%s", p->num);
		printf("请输入学生语文成绩：\n");
		scanf("%d", &chinese);
		printf("请输入学生数学成绩：\n");
		scanf("%d", &math);
		printf("请输入学生英语成绩：\n");
		scanf("%d", &english);
		p->chinese = chinese;
		p->english = english;
		p->math = math;
		average = (chinese + math + english) / 3.0;
		p->average = average;

		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	return head;
}
//查询学生信息
int find_std(struct student* p) {
	int chos;
	int q;
	printf("--------1.按学号查询学生-------\n");
	printf("--------2.按姓名查询学生-------\n");
	printf("------------3.退出-----------\n");
	printf("请输入：");
	scanf("%d", &chos);
	switch (chos) {
	case 1:q = find_num(p); break;
	case 2:q = find_name(p); break;
	case 3:return 0; break;
	default: printf("输入错误！请重新输入！"); return 0;
	}
	if (q == 0)
		printf("未找到该学生！学生不存在！");

	return 1;
}


//按学号查询学生
int find_num(struct student* head) {
	char num[20];
	printf("请输入学生学号:");
	scanf("%s", num);
	while (1)
	{
		if (!strcmp(head->num, num))
		{
			printf("学生姓名：%s\t", head->name);
			printf("学生年龄：%d\t", head->age);
			printf("学生学号：%s\t", head->num);
			printf("学生语文成绩：%d\t", head->chinese);
			printf("学生数学成绩：%d\t", head->math);
			printf("学生英语成绩：%d\t", head->english);
			printf("学生平均分：%lf\t", head->average);
			return 1;
		}
		else
		{
			if (head->next == NULL)
				break;
			head = head->next;
		}
	}
	return 0;
}
//按姓名查询学生
int find_name(struct student* head) {
	char name[20];
	printf("请输入学生姓名:");
	scanf("%s", name);
	while (1)
	{
		if (!strcmp(head->name, name))
		{
			printf("学生姓名：%s\t", head->name);
			printf("学生年龄：%d\t", head->age);
			printf("学生学号：%s\t", head->num);
			printf("学生语文成绩：%d\t", head->chinese);
			printf("学生数学成绩：%d\t", head->math);
			printf("学生英语成绩：%d\t", head->english);
			printf("学生平均分：%lf\t", head->average);
			return 1;
		}
		else
		{
			if (head->next == NULL)
				break;
			head = head->next;
		}
	}
	return 0;
}
//删除学生信息
struct student* delete_std(struct student* head) {
	int chos;
	printf("--------1.按学号删除学生-------\n");
	printf("--------2.按姓名删除学生-------\n");
	printf("------------3.退出-----------\n");
	printf("请输入：");
	scanf("%d", &chos);
	switch (chos) {
	case 1:head = delete_num(head); break;
	case 2:head = delete_name(head); break;
	case 3:return head;
	default: printf("输入错误！请重新输入！"); return head;
	}
	return head;
}
//按学生学号删除学生信息
struct student* delete_num(struct student* head)
{
	int n = 0, chos;
	char num[20];
	struct student* p, * q, * tail;
	p = head;
	tail = head;
	q = head->next;
	printf("请输入学生学号:");
	scanf("%s", num);
	printf("删除学生的信息如下\n");
	while (1)
	{
		if (!strcmp(head->num, num))
		{
			printf("学生姓名：%s\t", head->name);
			printf("学生年龄：%d\t", head->age);
			printf("学生学号：%s\t", head->num);
			printf("学生语文成绩：%d\t", head->chinese);
			printf("学生数学成绩：%d\t", head->math);
			printf("学生英语成绩：%d\t", head->english);
			printf("学生平均分：%lf\t", head->average);
			n = 1;
			break;
		}
		else
		{
			if (head->next == NULL)
				break;
			head = head->next;
		}
	}
	if (n == 0)
	{
		printf("未找到该学生！学生不存在！");
		return head;
	}
	printf("是否确定删除！\n");
	printf("1.YES\n");
	printf("2.NO\n");
	scanf("%d", &chos);
	if (chos == 1)
	{
		while (1)
		{
			if (!strcmp(tail->num, num))
			{
				tail = tail->next;
				free(p);
				return tail;
			}
			else if (!strcmp(q->num, num))
			{
				p->next = q->next;
				free(q);
				return tail;
			}
			else
			{
				if (p->next == NULL)
					break;
				p = p->next;
				q = q->next;
			}
		}
	}
	else if (chos == 2)
		return head;
	else {
		printf("输入错误！请重新输入！"); return head;
	}
	return NULL;
}
//按学生姓名删除学生信息
struct student* delete_name(struct student* head)
{
	int n = 0, chos;
	char name[20];
	struct student* p, * q, * tail;
	p = head;
	tail = head;
	q = head->next;
	printf("请输入学生姓名:");
	scanf("%s", name);
	printf("删除学生的信息如下\n");
	while (1)
	{
		if (!strcmp(head->name, name))
		{
			printf("学生姓名：%s\t", head->name);
			printf("学生年龄：%d\t", head->age);
			printf("学生学号：%s\t", head->num);
			printf("学生语文成绩：%d\t", head->chinese);
			printf("学生数学成绩：%d\t", head->math);
			printf("学生英语成绩：%d\t", head->english);
			printf("学生平均分：%lf\t", head->average);
			n = 1;
			break;
		}
		else
		{
			if (head->next == NULL)
				break;
			head = head->next;
		}
	}
	if (n == 0)
	{
		printf("未找到该学生！学生不存在！");
		return head;
	}
	printf("是否确定删除！\n");
	printf("1.YES\n");
	printf("2.NO\n");
	scanf("%d", &chos);
	if (chos == 1)
	{
		while (1)
		{
			if (!strcmp(tail->name, name))
			{
				tail = tail->next;
				free(p);
				return tail;
			}
			else if (!strcmp(q->name, name))
			{
				p->next = q->next;
				free(q);
				return tail;
			}
			else
			{
				if (p->next == NULL)
					break;
				p = p->next;
				q = q->next;
			}
		}
	}
	else if (chos == 2)
		return head;
	else {
		printf("输入错误！请重新输入！"); return head;
	}
	return NULL;
}

//修改学生信息
int update_std(struct student* head)
{
	int n = 0, chos, i;
	char num[20];
	int a[10] = { -1 };
	char ch = ' ';
	int chinese, math, english;
	double average;
	//struct student *p,*q,*tail;
	//p=head;
	//tail=head;
	//q=head->next;
	printf("请输入学生学号:");
	scanf("%s", num);
	printf("修改学生的信息如下\n");
	while (1)
	{
		if (!strcmp(head->num, num))
		{
			printf("学生姓名：%s\t", head->name);
			printf("学生年龄：%d\t", head->age);
			printf("学生学号：%s\t", head->num);
			printf("学生语文成绩：%d\t", head->chinese);
			printf("学生数学成绩：%d\t", head->math);
			printf("学生英语成绩：%d\t", head->english);
			printf("学生平均分：%lf\t", head->average);
			n = 1;
			break;
		}
		else
		{
			if (head->next == NULL)
				break;
			head = head->next;
		}
	}
	if (n == 0)
	{
		printf("未找到该学生！学生不存在！");
		return 0;
	}
	printf("是否确定修改！\n");
	printf("1.YES\n");
	printf("2.NO\n");
	scanf("%d", &chos);
	if (chos == 1)
	{
		printf("1.姓名\t"); printf("2.年龄\t"); printf("3.学号\t"); printf("4.语文成绩\t"); printf("5.数学成绩\t"); printf("6.英语成绩\t");
		printf("输入要修改的项目，可多选！用空格隔开！\n");
		for (i = 0; ch == ' '; i++)
		{
			scanf("%d", &a[i]);
			ch = getchar();
		}
		for (i = 0; a[i]; i++)
		{
			switch (a[i])
			{
			case 1:printf("请输入修改后姓名:"); scanf("%s", head->name); break;
			case 2:printf("请输入修改后年龄:"); scanf("%d", &head->age); break;
			case 3:printf("请输入修改后学号:"); scanf("%s", head->num); break;
			case 4:printf("请输入修改后语文成绩:"); scanf("%d", &chinese); head->chinese = chinese; break;
			case 5:printf("请输入修改后数学成绩:"); scanf("%d", &math); head->math = math; break;
			case 6:printf("请输入修改后英语成绩:"); scanf("%d", &english); head->english = english; break;
			default:printf("输入错误！"); return 0;;

			}
		}
		average = (head->chinese + head->math + head->english) / 3.0;
		head->average = average;
		return 1;
	}
	else  if (chos == 2)
		return 0;
	else {
		printf("输入错误！请重新输入！"); return 0;
	}
}
void sort_std(struct student* head) {
	struct student* p[10];
	//struct student *q;
	int i = 0, k, j, g;
	for (i = 0; head != NULL; i++)
	{
		p[i] = (struct student*)malloc(sizeof(struct student));
		strcpy(p[i]->name, head->name);
		p[i]->age = head->age;
		strcpy(p[i]->num, head->num);
		p[i]->chinese = head->chinese;
		p[i]->math = head->math;
		p[i]->english = head->english;
		p[i]->average = head->average;
		p[i]->next = NULL;
		head = head->next;
	}
	for (k = 0; k < i - 1; k++)
		for (j = 0; j < i - k - 1; j++)
		{
			if (p[j]->average < p[j + 1]->average)
			{
				struct student* temp;
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	for (g = 0; g < i; g++)
		show(p[g]);
}
//显示学生信息
int show(struct student* p) {
	while (1) {
		if (p == NULL)
			return 0;
		printf("学生姓名：%s\t", p->name);
		printf("学生年龄：%d\t", p->age);
		printf("学生学号：%s\t", p->num);
		printf("学生语文成绩：%d\t", p->chinese);
		printf("学生数学成绩：%d\t", p->math);
		printf("学生英语成绩：%d\t", p->english);
		printf("学生平均分：%lf\t", p->average);
		printf("\n");
		if (p->next == NULL)
			break;
		p = p->next;
	}
	return 0;
}
