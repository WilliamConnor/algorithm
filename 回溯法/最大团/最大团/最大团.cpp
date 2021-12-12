#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define N 105
using namespace std;

//���������-���ݷ�-(Maximum Clique Problem, MCP)-��bug
bool G[N][N];//ͼ
bool x[N];//��¼ÿһ���ڵ��Ƿ�ѡ��
int bestx[N];//��¼ѡ�ýڵ���÷���
int cnt = 0;//��¼�Žڵ���
int bestc;//��¼����Žڵ���
int n;//n-�ܽڵ�������Ϊ�޽�����

void MCP(int i)
{
	if (i > n)//�������˵���Ǹ��÷���
	{
		bestc = cnt;
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = x[j];//���¸��÷���
		}
		return;
	}
	x[i] = 1;//�ȼٶ�x[i] = 1�����֮��x[i] = 1����������������ѡ����㣬�ҽ���������
	for (int j = 1; j < i; j++)//ɨ�赱ǰ��
	{
		if (x[j] == 1 && G[i][j] == 0)//�����ǰ��x[j]��ѡ�ã�����ͼ G[i][j]�ǲ���ͨ�ģ���flagΪ0��ʾ��ѡ����ڵ㣬����������
			x[i] = 0;
			break;
	}
	if (x[i])//ѡ������ڵ�
	{
		cnt++;//��ѡ�ڵ�++
		MCP(i + 1);//������һ��

		cnt--;//�ָ�����cnt
	}
	x[i] = 0;//�ָ��ڵ�Ϊδѡ״̬
	if (cnt + (n - i) > bestc)//�����ǰ��ѡ�ڵ�+ʣ���ѡ�ڵ�>��ǰ��֪��������ڵ�����������������
	{
		x[i] = 0;
		MCP(i + 1);
	}
	return;//һ������
}

int main()
{
	cout << "�����붥������n:" << endl;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> G[i][j];
		}
	}

	MCP(1);
	cout << "����Ŷ�����Ϊ:" << bestc << endl;
	cout << "�������ѡ����Ϊ:";
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
		{
			cout << i << " ";//�Ե�ı�����
		}
		//cout << bestx[i] << " ";//��0-1��ʽ���
	}
	return 0;
}
//���� ����:5   0 1 0 1 1   1 0 1 0 1   0 1 0 0 1   1 0 0 0 1   1 1 1 1 0
//��� 1 1 0 0 1  (��ʾѡ����1,2,5�Ŷ�����������)


//�������뷽��
//int main()
//{
//	int e, u, v;//e,u,v-�������Լ��ߵ���������
//	cout << "�����붥������n:" << endl;
//	cin >> n;
//	cout << "�����������e:" << endl;
//	cin >> e;
//	for (int i = 1; i <= e; i++)
//	{
//		cout << "�����붥��" << i << endl;
//		cin >> u >> v;
//		G[u][v] = 1;
//	}
//	MCP(1);
//	cout << "����Ŷ�����Ϊ:" << bestc << endl;
//	cout << "�������ѡ����Ϊ:";
//	for (int i = 1; i <= n; i++)
//	{
//		cout << bestx[i] << " ";
//	}
//	return 0;
//}
////���� ����:5 14  1 2  1 4  1 5  2 1  2 3  2 5  3 2  3 5  4 1  4 5  5 1  5 2  5 3  5 4 
////��� 1 1 0 0 1  (��ʾѡ����1,2,5�Ŷ�����������)