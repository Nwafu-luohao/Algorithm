#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 99999

/*
�����ⷨ
����˵��
arr -- ��������
length -- ����ĳ���
s -- ��Ҫ�Ƚϵ�ֵ
����ֵ�� ���ط���������С��������ĳ���
*/

int  violentSolution(int* arr, int length, int s) {
	
	int result = MAX;
	int subLength = 0;
	int sum = 0;

	for (int i = 0; i < length; i++) {
		sum = 0;
		for (int j = i; j < length; j++) {
			sum += arr[j];
			if (sum >= s) { // ���������������¼���������С����
				subLength = j - i + 1;
				result = result < subLength ? result : subLength;
			}
		}
	}
	
	return result == MAX ? 0 : result;
}

/*
�������ڷ���˫ָ�뷨��
����˵��
arr -- ��������
length -- ����ĳ���
s -- ��Ҫ�Ƚϵ�ֵ
����ֵ�� ���ط���������С��������ĳ���
*/

int slidingWindow(int* arr, int length, int s) {

	int sum = 0;
	int result = MAX;
	int subLength = 0;
	int i = 0; // i ��ʾ�������ڵ�ǰ��

	for (int j = 0; j < length; j++) { // j ��ʾ�������ڵ�ĩ��
		sum += arr[j];
		while (sum >= s) {
			subLength = j - i + 1;
			result = result < subLength ? result : subLength;
			sum -= arr[i++];  // ����ǰ����󻬶�
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