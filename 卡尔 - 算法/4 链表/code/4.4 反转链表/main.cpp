#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * Linklist;


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
双指针法反转链表
参数说明
L -- 传入链表
*/
void doublePointerReverse(Linklist &L) {
	Lnode* cur = L;
	Lnode* pre = NULL;
	
	while (cur) {
		Lnode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	L = pre;
}

/*
递归法反转链表
参数说明
L -- 传入链表
*/
Lnode* reverse(Lnode* cur, Lnode* pre) {
	if (cur == NULL) {
		return pre;
	}
	Lnode* tmp = cur->next;
	cur->next = pre;
	return reverse(tmp,cur);
}
void recursionReverse(Linklist& L) {
	L = reverse(L,NULL);
}

/*
头插法法反转链表
参数说明
L -- 传入链表
*/
void headInsertionReverse(Linklist& L) {
	Lnode* head = NULL;
	while (L)
	{
		Lnode* tmp = L->next;
		
		// 将原链表中的结点插入新的链表中
		L->next = NULL;
		if (head != NULL) {
			L->next = head;
		}
		head = L;

		// 原链表向后移动
		L = tmp;
	}
	L = head;
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

	// 双指针法
	printf("双指针法: \n");
	doublePointerReverse(L);
	print(L);

	// 递归法
	printf("递归法: \n");
	recursionReverse(L);
	print(L);

	// 头插法反转
	printf("头插法反转: \n");
	headInsertionReverse(L);
	print(L);

	return 0;
}