#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ������
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode;

// ����ṹ��
typedef struct LinkList {
	int size;
	Lnode* head = NULL;
	Lnode* rear = NULL;
}LinkList;

/*
��ʼ������
����˵��
L -- ��������
*/
void listInit(LinkList& L) {

	// ��̬����һ������ͷ���
	Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
	newNode->next = NULL;
	L.size = 0;
	L.head = newNode;
	L.rear = newNode;
}


/*
ͷ�巨��������
����˵��
L -- ��������
x -- ����ϵ�����
*/
bool addAtHead(LinkList& L, int x) {

	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	if (newnode == NULL) {
		return false;
	}
	newnode->next = NULL;
	newnode->data = x;

	if (L.head == L.rear) { // ������
		L.rear = newnode;
	}
	newnode->next = L.head->next;
	L.head->next = newnode;
	L.size++;
	
	return true;
}

/*
β�巨��������
����˵��
L -- ��������
x -- ����ϵ�����
*/
bool addAtTail(LinkList& L, int x) {

	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	if (newnode == NULL) {
		return false;
	}
	newnode->next = NULL;
	newnode->data = x;

	if (L.head == L.rear) { // ������
		L.rear = newnode;
		L.head->next = newnode;
	}
	else { // ���ǿ�����
		L.rear->next = newnode;
		L.rear = L.rear->next;
	}
	L.size++;

	return true;
}

/*
ָ��λ�ò���������һ������Ӧ��λ��Ϊ0
����˵��
L -- ��������
index -- Ҫ�����λ��
x -- ����ϵ�����
*/
bool addAtIndex(LinkList& L, int index, int x) {

	if (index <0 && index>L.size) {
		return false;
	}
	if (index == 0) {
		addAtHead(L, x); // ʹ��ͷ�巨
		return true;
	}
	else if (index == L.size) {
		addAtTail(L, x); // ʹ��β�巨
		return true;
	}
	else {
		Lnode* cur = L.head;
		while (index--) {
			cur = cur->next;
		}
		Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
		newnode->data = x;
		newnode->next = NULL;

		newnode->next = cur->next;
		cur->next = newnode;
		L.size++;
	}

	return true;
}

/*
��ȡ��index��������ֵ
����˵��
L -- ��������
index -- ��ȡ�ڵ��λ��
����ֵ��ָ��λ�ý���ֵ
*/

int  getElem(LinkList& L, int index) {

	if (index <0 || index > L.size - 1) { //�����в��������ҵ�λ��
		return -1; 
	}
	Lnode* cur = L.head;
	while (index--) {
		cur = cur->next;
	}
	return cur->next->data;
}


/*
ɾ����index�����
����˵��
L -- ��������
index -- ��ȡ�ڵ��λ��
x -- Ҫɾ������ֵ
*/

bool  deleteAtIndex(LinkList& L, int index, int& x) {

	if (index <0 || index > L.size - 1) { //�����в��������ҵ�λ��
		return false;
	}
	Lnode* cur = L.head;
	while (index--) {
		cur = cur->next;
	}
	x =  cur->next->data;
	Lnode* p = cur->next;
	if (p == L.rear) {
		L.rear = cur;
	}
	cur->next = p->next;
	free(p);
	L.size--;
}

/*
��ӡ����
����˵��
L -- ��������
*/
void printLinkList(LinkList L) {

	if (L.size == 0) {
		return;
	}
	Lnode* cur = L.head->next;
	while (cur){
		printf("%3d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


int main() {

	// ����������ʼ��
	LinkList L;
	listInit(L);

	// ͷ�巨����ڵ�
	addAtHead(L, 1);
	addAtHead(L, 2);
	addAtHead(L, 3);

	// ��ӡ����
	printLinkList(L);

	// β�巨����ڵ�
	addAtTail(L, 4);
	addAtTail(L, 5);
	addAtTail(L, 6);

	// ��ӡ����
	printLinkList(L);

	// ָ��λ�ò���
	addAtIndex(L, 0,0);
	addAtIndex(L, 7, 99);
	addAtIndex(L, 1, 11);

	// ��ӡ����
	printLinkList(L);

	// ����ָ��λ�ý���ֵ
	int index = -1;
	printf("\n");
	printf("%3d: %3d\n", index,getElem(L, index));
	index = 0;
	printf("%3d: %3d\n", index,getElem(L, index));
	index = 5;
	printf("%3d: %3d\n\n", index,getElem(L, index));

	// ɾ��ָ��λ�õĽڵ�
	int val = 0;
	printLinkList(L);
	deleteAtIndex(L, 8, val);
	printf("Delete at 8: ");
	printLinkList(L);
	deleteAtIndex(L, 0, val);
	printf("Delete at 0: ");
	printLinkList(L);
	deleteAtIndex(L, 3, val);
	printf("Delete at 3: ");
	printLinkList(L);

	return 0;
}