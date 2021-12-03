#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

using namespace std;

////最长公共子序列-动态规划-只计算长度
////给定str1,str2两个字符串，求最长公共子序列
////比如algorithms和alchemist，最长公共子序列为alhms
//int main()
//{
//	string str1 = "alrgoithms";//长10
//	string str2 = "alchemist";//长9
//	int dp[11][10] = { {0} };//留dp[0][0]做空值，从dp[1][]和dp[][1]开始
//
//	for (int i = 1; i < 11; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			//如果str1的第i字符等于str2的第j字符，则dp[i][j]为左上角的dp值
//			if (str1[i] == str2[j])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			//否则当前dp从左边和上方的dp值选择更大者
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//	cout << "最大子序列长度为" << dp[10][9];
//	return 0;
//}






//最长公共子序列-要求把该最长公共子序列(LCS)也写出来-有bug,首字符a没打印出来
string str1 = "alrgoithms";//长10
string str2 = "alchemist";//长9
int dp[11][10] = { {0} };//留dp[0][0]做空值，从dp[1][]和dp[][1]开始
int trace[11][10] = { {0} };//选择LCS的路径
void LCS(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (trace[i][j] == 1)
	{
		LCS(i - 1, j - 1);
		cout << str1[i];
	}
	else if (trace[i][j] == 2)
		LCS(i - 1, j);
	else
		LCS(i, j - 1);
}
int main()
{
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			//如果str1的第i字符等于str2的第j字符，则dp[i][j]为左上角的dp值
			if (str1[i] == str2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				trace[i][j] = 1;//trace为1，说明当前选择左上方的字符
			}
			//否则当前dp从左边和上方的dp值选择更大者
			else if (dp[i - 1][j] > dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
				trace[i][j] = 2;//trace为2，选择上方
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
				trace[i][j] = 3;//选择左方路径
			}
		}
	}
	cout << "最大子序列长度为" << dp[10][9] << endl;
	LCS(10, 9);
	return 0;
}