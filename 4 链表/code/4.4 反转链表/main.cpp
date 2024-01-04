#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode, * Linklist;


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
˫ָ�뷨��ת����
����˵��
L -- ��������
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
�ݹ鷨��ת����
����˵��
L -- ��������
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
ͷ�巨����ת����
����˵��
L -- ��������
*/
void headInsertionReverse(Linklist& L) {
	Lnode* head = NULL;
	while (L)
	{
		Lnode* tmp = L->next;
		
		// ��ԭ�����еĽ������µ�������
		L->next = NULL;
		if (head != NULL) {
			L->next = head;
		}
		head = L;

		// ԭ��������ƶ�
		L = tmp;
	}
	L = head;
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

	// ˫ָ�뷨
	printf("˫ָ�뷨: \n");
	doublePointerReverse(L);
	print(L);

	// �ݹ鷨
	printf("�ݹ鷨: \n");
	recursionReverse(L);
	print(L);

	// ͷ�巨��ת
	printf("ͷ�巨��ת: \n");
	headInsertionReverse(L);
	print(L);

	return 0;
}