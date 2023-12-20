#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int BinarySearch1(int* arr, int len, int x) {

	int left = 0, right = len - 1;

	while (left <= right)
	{
		int mid = left + (right-left) / 2; // ��ֹ��������������Խ��
		if (arr[mid] == x) {
			return mid;  // �ҵ���Ŀ��ֵ
		}
		else if (arr[mid] > x) {
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}

	return -1; // δ�ҵ�Ŀ��ֵ
}

int BinarySearch2(int* arr, int len, int x) {

	int left = 0, right = len;

	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;  // �ҵ���Ŀ��ֵ
		}
		else if (arr[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return 0; // δ�ҵ�Ŀ��ֵ
}

int main() {
	
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int index = -1;
	index = BinarySearch1(arr, 10, 3);
	printf("%d\n", index);

	index = BinarySearch2(arr, 10, 6);
	printf("%d\n", index);

	return 0;
}