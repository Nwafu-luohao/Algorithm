#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
ʵ����������
����˵��
arr -- �����ά����
n -- ����ĳ���
*/

void  Solution(int** arr, int n) {

	int startX = 0, startY = 0;
	int offset = 1;
	int count = 1;
	int loop= n / 2;
	int mid = n / 2; //������м�λ��
	int i = 0, j = 0;

	while (loop--) {
		// �ϱ�
		for (j = startY; j < n - offset; j++) {
			arr[startX][j] = count++;
		}
		// �ұ�
		for (i = startX; i < n - offset; i++) {
			arr[i][j] = count++;
		}
		// �±�
		for (; j > startY; j--) {
			arr[i][j] = count++;
		}
		// ���
		for (; i > startX; i--) {
			arr[i][startY] = count++;
		}

		startX++;
		startY++;
		offset++;
	}

	if (n % 2 == 1) {
		arr[mid][mid] = count;
	}
}

/*
��ӡ����
����˵��
arr -- �����ά����
n -- ����ĳ���
*/
void print(int **arr, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

}


int main() {

	int n = 7;

	// ��̬������ά����
	int** arr = NULL;
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	// ʵ����������
	Solution(arr, n);
	// ��ӡ��������
	print(arr, n);
	// �ͷŶ�ά����
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	return 0;
}