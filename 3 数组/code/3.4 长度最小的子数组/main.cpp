#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 99999

/*
暴力解法
参数说明
arr -- 传入数组
length -- 数组的长度
s -- 将要比较的值
返回值： 返回符合条件最小的子数组的长度
*/

int  violentSolution(int* arr, int length, int s) {
	
	int result = MAX;
	int subLength = 0;
	int sum = 0;

	for (int i = 0; i < length; i++) {
		sum = 0;
		for (int j = i; j < length; j++) {
			sum += arr[j];
			if (sum >= s) { // 如果满足条件，记录子数组的最小长度
				subLength = j - i + 1;
				result = result < subLength ? result : subLength;
			}
		}
	}
	
	return result == MAX ? 0 : result;
}

/*
滑动窗口法（双指针法）
参数说明
arr -- 传入数组
length -- 数组的长度
s -- 将要比较的值
返回值： 返回符合条件最小的子数组的长度
*/

int slidingWindow(int* arr, int length, int s) {

	int sum = 0;
	int result = MAX;
	int subLength = 0;
	int i = 0; // i 表示滑动窗口的前端

	for (int j = 0; j < length; j++) { // j 表示滑动窗口的末端
		sum += arr[j];
		while (sum >= s) {
			subLength = j - i + 1;
			result = result < subLength ? result : subLength;
			sum -= arr[i++];  // 窗口前端向后滑动
		}
	}

	return result == MAX ? 0 : result;
}


int main() {

	int arr[10] = { 1,3,4,5,6,7,5,4,3,4 };
	int s = 7;
	int min_size = violentSolution(arr, 10, s);
	printf("The min size is %d\n", min_size);

	printf("\n");

	s = 11;
	min_size = slidingWindow(arr, 10, s);
	printf("The min size is %d\n", min_size);

	return 0;
}