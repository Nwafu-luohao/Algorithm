#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
实现螺旋矩阵
参数说明
arr -- 传入二维数组
n -- 数组的长度
*/

void  Solution(int** arr, int n) {

	int startX = 0, startY = 0;
	int offset = 1;
	int count = 1;
	int loop= n / 2;
	int mid = n / 2; //矩阵的中间位置
	int i = 0, j = 0;

	while (loop--) {
		// 上边
		for (j = startY; j < n - offset; j++) {
			arr[startX][j] = count++;
		}
		// 右边
		for (i = startX; i < n - offset; i++) {
			arr[i][j] = count++;
		}
		// 下边
		for (; j > startY; j--) {
			arr[i][j] = count++;
		}
		// 左边
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
打印数组
参数说明
arr -- 传入二维数组
n -- 数组的长度
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

	// 动态创建二维数组
	int** arr = NULL;
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	// 实现螺旋矩阵
	Solution(arr, n);
	// 打印螺旋矩阵
	print(arr, n);
	// 释放二维数组
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	return 0;
}