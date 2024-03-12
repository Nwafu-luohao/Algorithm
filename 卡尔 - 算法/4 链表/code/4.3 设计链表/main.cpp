#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 链表结点
typedef struct Lnode {
	int data;
	struct Lnode* next;
}Lnode;

// 链表结构体
typedef struct LinkList {
	int size;
	Lnode* head = NULL;
	Lnode* rear = NULL;
}LinkList;

/*
初始化链表
参数说明
L -- 传入链表
*/
void listInit(LinkList& L) {

	// 动态分配一个虚拟头结点
	Lnode* newNode = (Lnode*)malloc(sizeof(Lnode));
	newNode->next = NULL;
	L.size = 0;
	L.head = newNode;
	L.rear = newNode;
}


/*
头插法插入链表
参数说明
L -- 传入链表
x -- 结点上的数据
*/
bool addAtHead(LinkList& L, int x) {

	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	if (newnode == NULL) {
		return false;
	}
	newnode->next = NULL;
	newnode->data = x;

	if (L.head == L.rear) { // 空链表
		L.rear = newnode;
	}
	newnode->next = L.head->next;
	L.head->next = newnode;
	L.size++;
	
	return true;
}

/*
尾插法插入链表
参数说明
L -- 传入链表
x -- 结点上的数据
*/
bool addAtTail(LinkList& L, int x) {

	Lnode* newnode = (Lnode*)malloc(sizeof(Lnode));
	if (newnode == NULL) {
		return false;
	}
	newnode->next = NULL;
	newnode->data = x;

	if (L.head == L.rear) { // 空链表
		L.rear = newnode;
		L.head->next = newnode;
	}
	else { // 不是空链表
		L.rear->next = newnode;
		L.rear = L.rear->next;
	}
	L.size++;

	return true;
}

/*
指定位置插入链表，第一个结点对应的位置为0
参数说明
L -- 传入链表
index -- 要插入的位置
x -- 结点上的数据
*/
bool addAtIndex(LinkList& L, int index, int x) {

	if (index <0 && index>L.size) {
		return false;
	}
	if (index == 0) {
		addAtHead(L, x); // 使用头插法
		return true;
	}
	else if (index == L.size) {
		addAtTail(L, x); // 使用尾插法
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
获取第index个结点的数值
参数说明
L -- 传入链表
index -- 获取节点的位置
返回值：指定位置结点的值
*/

int  getElem(LinkList& L, int index) {

	if (index <0 || index > L.size - 1) { //链表中不存在所找的位置
		return -1; 
	}
	Lnode* cur = L.head;
	while (index--) {
		cur = cur->next;
	}
	return cur->next->data;
}


/*
删除第index个结点
参数说明
L -- 传入链表
index -- 获取节点的位置
x -- 要删除结点的值
*/

bool  deleteAtIndex(LinkList& L, int index, int& x) {

	if (index <0 || index > L.size - 1) { //链表中不存在所找的位置
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
打印链表
参数说明
L -- 传入链表
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

	// 创建链表并初始化
	LinkList L;
	listInit(L);

	// 头插法插入节点
	addAtHead(L, 1);
	addAtHead(L, 2);
	addAtHead(L, 3);

	// 打印链表
	printLinkList(L);

	// 尾插法插入节点
	addAtTail(L, 4);
	addAtTail(L, 5);
	addAtTail(L, 6);

	// 打印链表
	printLinkList(L);

	// 指定位置插入
	addAtIndex(L, 0,0);
	addAtIndex(L, 7, 99);
	addAtIndex(L, 1, 11);

	// 打印链表
	printLinkList(L);

	// 查找指定位置结点的值
	int index = -1;
	printf("\n");
	printf("%3d: %3d\n", index,getElem(L, index));
	index = 0;
	printf("%3d: %3d\n", index,getElem(L, index));
	index = 5;
	printf("%3d: %3d\n\n", index,getElem(L, index));

	// 删除指定位置的节点
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