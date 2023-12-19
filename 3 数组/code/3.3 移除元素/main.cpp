#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 暴力解法
int  violentSolution(int* arr, int length, int val) {

	for (int i = 0; i < length; i++) {
		if (arr[i] == val) {
			for (int j = i + 1; j < length; j++) {
				arr[j - 1] = arr[j];
			}
			i--; // 重新判断i位置元素是否等于val
			length--; // 数组的长度-1
		}
	}

	return length;
}

// 双指针法（快慢指针法）
int doublePointer(int* arr, int length, int val) {

	int slow = 0;
	for (int fast = 0; fast < length; fast++) {
		if (arr[fast] != val) {
			arr[slow++] = arr[fast];
		}
	}

	return slow;
}

// 打印新的数组
void print(int *arr, int length) {

	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {

	int arr[10] = {1,3,4,5,6,7,5,4,3,4};
	int val = 3;
	int size = violentSolution(arr, 10, val);
	printf("The size is %d\n", size);
	print(arr, size);

	printf("\n");

	int arr1[10] = { 1,3,4,5,6,7,5,4,3,4 };
	val = 5;
	size = doublePointer(arr1, 10, val);
	printf("The size is %d\n", size);
	print(arr1, size);

	return 0;
}