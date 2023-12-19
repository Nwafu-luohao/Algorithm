#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// �����ⷨ
int  violentSolution(int* arr, int length, int val) {

	for (int i = 0; i < length; i++) {
		if (arr[i] == val) {
			for (int j = i + 1; j < length; j++) {
				arr[j - 1] = arr[j];
			}
			i--; // �����ж�iλ��Ԫ���Ƿ����val
			length--; // ����ĳ���-1
		}
	}

	return length;
}

// ˫ָ�뷨������ָ�뷨��
int doublePointer(int* arr, int length, int val) {

	int slow = 0;
	for (int fast = 0; fast < length; fast++) {
		if (arr[fast] != val) {
			arr[slow++] = arr[fast];
		}
	}

	return slow;
}

// ��ӡ�µ�����
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