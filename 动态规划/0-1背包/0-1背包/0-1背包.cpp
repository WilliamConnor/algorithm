#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

using namespace std;

//0-1背包-除max函数外用C语言编写
//案例：物品数4个，载重量10，但是数组创建时多建一个元素，第一个元素设为0，方便观看
//把以下数据写在main外面是作为全局变量，方便所有函数之间使用，不需要传参
int w[5] = { 0,2,3,4,5 };//每个物品重量
int v[5] = { 0,3,4,5,8 };//每个物品价值
int dp[5][9] = { {0} };//动态规划表
int index = 4;//物品数
int capacity = 8;//载重量
int item[5] = { 0 };//为了回溯最优算法选择了哪些物品，所建立的数组
//void GetSelect(int i, int j);//追溯最优结果下物品0-1选择情况
int main()
{
	
	//01背包本体
	for (int i = 1; i <= index; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];//如果当前的容量j已经不足以装下当前物品重量w[i]，则不选择这个物品，跳至下一个物品，表现为[i-1]
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);//核心
			}//第i物品第j剩余重量下的结果等于后面两者的更大值：
		}//①不选当前物品直接跳至下一个，物品 - 1②选择当前物品，物品 - 1，同时剩余重量j - 相应物品重量w[i]，同时在后面加上物品价值v[i]
	}
	//打印所有动态规划表结果
	for (int i = 1; i <= index; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			printf("dp[%d][%d]=%d ", i, j, dp[i][j]);
		}
		printf("\n");
	}
	//GetSelect(4, 8);
}
//void GetSelect(int i, int j)//有bug
//{
//	//追溯最优结果所选择的物品
//	if (i >= 0)
//	{
//		if (dp[i][j] == dp[i - 1][j])
//		{
//			item[i] = 0;
//			GetSelect(i - 1, j);
//		}
//	}
//	else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i])
//	{
//		item[i] = 1;
//		GetSelect(i - 1, j - w[i]);
//	}
//	//打印物品0-1选择情况
//	for (int i = 1; i <= index; i++)
//	{
//		printf("%d", item[i]);
//	}
//}

//0-1背包-vector版本函数
#include<vector>
vector<vector<int>> memo;
int bestvalue(vector<int>& w, vector<int>& v, int index, int capacity)
{
	if (capacity <= 0)
		return 0;
	if (index < 0)
		return 0;
	if (memo[index][capacity] != -1)
		return memo[index][capacity];

	int ret = bestvalue(w, v, index - 1, capacity);
	if (capacity > w[index])
		ret = max(ret, bestvalue(w, v, index - 1, capacity - w[index]) + v[index]);
	memo[index][capacity] = ret;
	return ret;
}

