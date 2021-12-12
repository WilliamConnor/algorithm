#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#define N 105
using namespace std;

int main()
{

	int a[N] = { 31,-41,59,26,-53,58,97,-93,-23,84 };//数据
	int tempSum = 0;//存放从1到j区间的当前最大字段和
	int maxSum = 0;//存放整个数据最大字段和
	for (int j = 0; j < 10; j++)
	{
		tempSum = max(tempSum + a[j], a[j]);//如果tempSum是负数，那还不如直接从a[j]开始新的序列
		if (tempSum > maxSum)
		{
			maxSum = tempSum;//更新整个数组的最大子段和
		}
	}
	cout << maxSum<<endl;//187
	return 0;
}
