#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 二分查找
/*
	在有序数组里面查找对应元素的下标。
	重点在于边界值的控制。（左闭右闭，左闭右开）
*/

// 左闭右闭
int binary_search1(int *arr, int size, int x) {

	int left = 0;
	int right = size-1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > x) {
			right = mid - 1;
		}
		else if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

// 左闭右开
int binary_search2(int* arr, int size, int x) {

	int left = 0;
	int right = size;

	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] > x) {
			right = mid;
		}
		else if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}


int main() {

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int result;
	result = binary_search1(arr, 10, 4);
	printf("result =%2d\n", result);
	result = binary_search2(arr, 10, 7);
	printf("result =%2d\n", result);

	return 0;
}