#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#define N 105
using namespace std;

int main()
{

	int a[N] = { 31,-41,59,26,-53,58,97,-93,-23,84 };//����
	int tempSum = 0;//��Ŵ�1��j����ĵ�ǰ����ֶκ�
	int maxSum = 0;//���������������ֶκ�
	for (int j = 0; j < 10; j++)
	{
		tempSum = max(tempSum + a[j], a[j]);//���tempSum�Ǹ������ǻ�����ֱ�Ӵ�a[j]��ʼ�µ�����
		if (tempSum > maxSum)
		{
			maxSum = tempSum;//�����������������Ӷκ�
		}
	}
	cout << maxSum<<endl;//187
	return 0;
}
