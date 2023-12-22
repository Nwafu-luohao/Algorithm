#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode,*Linklist;


/*
ͷ�巨��������
����˵��
L -- ��������
x -- ����ϵ�����
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
ֱ��ɾ����
����˵��
arr -- �����ά����
n -- ����ĳ���
*/

void  directMethod(Linklist& L, int val) {
	
	// ɾ������������ͷ���
	while (L != NULL && L->data == val) {
		Lnode* p = L;
		L = L->next;
		free(p);
	}
	// ɾ�������������������
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
����ͷ��㷨
����˵��
arr -- �����ά����
n -- ����ĳ���
*/
void virtualHeadMethod(Linklist& L, int val) {

	Lnode* dummyHead = NULL;
	dummyHead = (Lnode*)malloc(sizeof(Lnode)); // ����һ������ͷ���
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
��ӡ����
����˵��
L -- ��������
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

	// ��������
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

	// ֱ��ɾ����
	printf("Result: delete (%d)\n",7);
	directMethod(L, 7);
	print(L);
	// ����ͷ��㷨
	printf("Result: delete (%d)\n", 2);
	directMethod(L, 2);
	print(L);

	return 0;
}