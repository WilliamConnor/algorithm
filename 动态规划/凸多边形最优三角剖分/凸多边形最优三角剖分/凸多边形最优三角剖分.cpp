#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#define N 7
using namespace std;

//͹��������������ʷ�-��̬�滮-�������
int weight[][N] = { {0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},{1,2,1,6,0,1},{4,3,4,2,1,0} };//͹����ε�Ȩ�������ģ�����������cin����
int MinWeightTriangulation(int n, int** t, int** s);//�����������ʷ�   n��������N-1   t[i][j]�����i��j������Ȩ��   s[i][j]������i,j��Ϊ�����ѡȡ�Ĺ��������εĵ���������
void Traceback(int i, int j, int** s);//�������溯�����õ�s����׷��ѡȡ����Щ���㣬i,j��ʾ��ʼ�ͽ�������
int Weight(int a, int b, int c);//���������������������Σ�������Ȩ���

int main()
{
	//���ﶼ����new������ά����t��s
	int** t = new int* [N];
	int** s = new int* [N];
	for (int i = 0; i < N; i++)
	{
		t[i] = new int[N];
		s[i] = new int[N];
	}

	cout << "�����ʷ�ֵΪ:" << MinWeightTriangulation(N - 1, t, s) << endl;
	cout << "���������ʷ�ѡ��Ķ���:" << endl;
	Traceback(1, 5, s);
	return 0;
}

int Weight(int a, int b, int c)
{
	return weight[a][b] + weight[a][c] + weight[b][c];
}

int MinWeightTriangulation(int n, int** t, int** s)
{
	for (int i = 0; i <= n; i++)
	{
		t[i][i] = 0;//���Լ����Լ���Ϊ0
	}
	for (int r = 2; r <= n; r++)//i��j�Ĳ�ֵ
	{
		for (int i = 1; i <= n - r + 1; i++)//n - r + 1�����һ��r�����ұ߽�
		{
			int j = i + r - 1;
			t[i][j] = t[i + 1][j] + Weight(i - 1, i, j);//k==i�����
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				//��ij����ΪA[i:k]*A[k+1][j]
				int u = t[i][k] + t[k + 1][j] + Weight(i - 1, k, j);
				if (u < t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
	return t[1][N - 2];
}

void Traceback(int i, int j, int** s)
{
	if (i == j)//�ݹ����������ij�м�û���ٷָ���
		return;
	Traceback(i, s[i][j], s);//��i��s[i][j]׷�ݣ�Ѱ��ÿһ�ε�����"��������"
	Traceback(s[i][j] + 1, j, s);//��s[i][j]+1��j
	cout << "�����ʷֶ���:V" << i - 1 << "��V" << j << "��V" << s[i][j] << endl;//��i,j��s[i][j]���������Ӧ���㹹��һ��������
}