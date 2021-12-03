#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

using namespace std;

////�����������-��̬�滮-ֻ���㳤��
////����str1,str2�����ַ������������������
////����algorithms��alchemist�������������Ϊalhms
//int main()
//{
//	string str1 = "alrgoithms";//��10
//	string str2 = "alchemist";//��9
//	int dp[11][10] = { {0} };//��dp[0][0]����ֵ����dp[1][]��dp[][1]��ʼ
//
//	for (int i = 1; i < 11; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			//���str1�ĵ�i�ַ�����str2�ĵ�j�ַ�����dp[i][j]Ϊ���Ͻǵ�dpֵ
//			if (str1[i] == str2[j])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			//����ǰdp����ߺ��Ϸ���dpֵѡ�������
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//	cout << "��������г���Ϊ" << dp[10][9];
//	return 0;
//}






//�����������-Ҫ��Ѹ������������(LCS)Ҳд����-��bug,���ַ�aû��ӡ����
string str1 = "alrgoithms";//��10
string str2 = "alchemist";//��9
int dp[11][10] = { {0} };//��dp[0][0]����ֵ����dp[1][]��dp[][1]��ʼ
int trace[11][10] = { {0} };//ѡ��LCS��·��
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
			//���str1�ĵ�i�ַ�����str2�ĵ�j�ַ�����dp[i][j]Ϊ���Ͻǵ�dpֵ
			if (str1[i] == str2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				trace[i][j] = 1;//traceΪ1��˵����ǰѡ�����Ϸ����ַ�
			}
			//����ǰdp����ߺ��Ϸ���dpֵѡ�������
			else if (dp[i - 1][j] > dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
				trace[i][j] = 2;//traceΪ2��ѡ���Ϸ�
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
				trace[i][j] = 3;//ѡ����·��
			}
		}
	}
	cout << "��������г���Ϊ" << dp[10][9] << endl;
	LCS(10, 9);
	return 0;
}