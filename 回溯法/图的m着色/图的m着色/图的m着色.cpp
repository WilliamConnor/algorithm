#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define N 20
using namespace std;

int n, m;//n��ͼ�Ķ�������m����ɫ��
int a = 1, b = 1, cnt = 0;//a,b��ֵ1���ܷ����ж�
int G[N][N];//ͼ���ڽӾ���
int color[N];//��ɫͼ

//�ж��Ƿ������ɫ
bool ok(int i)
{
	for (int j = 0; j <= n; j++)
	{
		if (G[i][j] && color[i] == color[j])//���ij��ͨ����ɫ��ȣ��򲻿���ɫ
			return false;
	}
	return true;
}

//���ݷ��ж�m��ɫ
void backtrack(int num)//�����ǵ�ǰҪ��ɫ�ĵ�
{
	if (num > n)//�����ǰ��Ŵ����ܵ�����˵����ɫ��ɣ��ѽ�����
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d", color[i]);//���ն���˳�������������Ӧ����ɫ���
		}
		cnt++;
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= m; i++)//�����m����ɫ�����ɫ
		{
			color[num] = i;//��num��������ɫi��
			if (ok(num))//Ҫ�ж��Ƿ����ɫ�����˴���ɫ��������ڵ�Ϊͬһ��ɫ
			{
				backtrack(num + 1);//������һ���������ɫ
			}
			color[num] = 0;//����㷵�ؾ�˵����ɫʧ�ܣ�����һ����ɫ������֮ǰ�Ȱ�color����0ֵ
		}
	}
}


int main()
{
	memset(G, 0, sizeof(G));//memset��Ԫ��ȫΪ0�������б��������������С
	memset(color, 0, sizeof(color));
	scanf("%d%d", &n, &m);
	while (scanf("%d%d", &a, &b) != EOF && a != 0 && b != 0)//�ƺ��Ǵ��ļ���ȡ������ͼ�Ĺ�ϵ����
	{
		G[a][b] = 1;
		G[b][a] = 1;
	}
	backtrack(1);//�ӵ�1����ɫ��ʼ�ж�
	printf("%d", cnt);//�����1��ʾ��ɫ�ɹ���0��ʾʧ��
	return 0;
}