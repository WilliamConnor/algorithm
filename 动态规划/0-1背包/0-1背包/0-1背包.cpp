#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

using namespace std;

//0-1����-��max��������C���Ա�д
//��������Ʒ��4����������10���������鴴��ʱ�ཨһ��Ԫ�أ���һ��Ԫ����Ϊ0������ۿ�
//����������д��main��������Ϊȫ�ֱ������������к���֮��ʹ�ã�����Ҫ����
int w[5] = { 0,2,3,4,5 };//ÿ����Ʒ����
int v[5] = { 0,3,4,5,8 };//ÿ����Ʒ��ֵ
int dp[5][9] = { {0} };//��̬�滮��
int index = 4;//��Ʒ��
int capacity = 8;//������
int item[5] = { 0 };//Ϊ�˻��������㷨ѡ������Щ��Ʒ��������������
//void GetSelect(int i, int j);//׷�����Ž������Ʒ0-1ѡ�����
int main()
{
	
	//01��������
	for (int i = 1; i <= index; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];//�����ǰ������j�Ѿ�������װ�µ�ǰ��Ʒ����w[i]����ѡ�������Ʒ��������һ����Ʒ������Ϊ[i-1]
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);//����
			}//��i��Ʒ��jʣ�������µĽ�����ں������ߵĸ���ֵ��
		}//�ٲ�ѡ��ǰ��Ʒֱ��������һ������Ʒ - 1��ѡ��ǰ��Ʒ����Ʒ - 1��ͬʱʣ������j - ��Ӧ��Ʒ����w[i]��ͬʱ�ں��������Ʒ��ֵv[i]
	}
	//��ӡ���ж�̬�滮����
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
//void GetSelect(int i, int j)//��bug
//{
//	//׷�����Ž����ѡ�����Ʒ
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
//	//��ӡ��Ʒ0-1ѡ�����
//	for (int i = 1; i <= index; i++)
//	{
//		printf("%d", item[i]);
//	}
//}

//0-1����-vector�汾����
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

