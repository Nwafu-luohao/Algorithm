#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode,*Linklist;


/*
头插法插入链表
参数说明
L -- 传入链表
x -- 结点上的数据
*/
bool headInsert(Linklist& L, int x) {

	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	if (newnode == NULL) {
		return false;
	}
	newnode->data = x;
	newnode->next = L;
	L = newnode;

	return true;
}

/*
直接删除法
参数说明
arr -- 传入二维数组
n -- 数组的长度
*/

void  directMethod(Linklist& L, int val) {
	
	// 删除符合条件的头结点
	while (L != NULL && L->data == val) {
		Lnode* p = L;
		L = L->next;
		free(p);
	}
	// 删除符合条件的其他结点
	Lnode* cur = L;
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->next->data == val) {
			Lnode* p = cur->next;
			cur->next = cur->next->next;
			free(p);
		}
		else {
			cur = cur->next;
		}
	}
}

/*
虚拟头结点法
参数说明
arr -- 传入二维数组
n -- 数组的长度
*/
void virtualHeadMethod(Linklist& L, int val) {

	Lnode* dummyHead = NULL;
	dummyHead = (Lnode*)malloc(sizeof(Lnode)); // 创建一个虚拟头结点
	dummyHead->next = L;

	Lnode* cur = dummyHead;
	while(cur != NULL && cur->next != NULL) {
		if (cur->next->data == val) {
			Lnode* p = cur->next;
			cur->next = cur->next->next;
			free(p);
		}
		else{
			cur = cur->next;
		}
	}
	L = dummyHead->next;
	free(dummyHead);
}


/*
打印链表
参数说明
L -- 传入链表
*/
void print(Linklist L) {

	if (L == NULL) {
		return;
	}
	while (L) {
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}


int main() {

	// 创建链表
	Linklist L = NULL;
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 5);
	headInsert(L, 7);
	headInsert(L, 7);

	printf("Linklist:\n");
	print(L);

	// 直接删除法
	printf("Result: delete (%d)\n",7);
	directMethod(L, 7);
	print(L);
	// 虚拟头结点法
	printf("Result: delete (%d)\n", 2);
	directMethod(L, 2);
	print(L);

	return 0;
}