#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#define N 1005
using namespace std;

struct Item
{
	double w;//����
	double v;//�۸�
	double p;//�Լ۱ȣ�����ɷָ���װ������
}item[N];
bool cmp(Item x, Item y)
{
	return x.p > y.p;//���ﰴ�Լ۱ȵݼ�����
}
int main()
{
	int n;
	double c;
	cout << "�����뱦������n�ͳ�����c" << endl;
	cin >> n >> c;
	cout << "������ÿ������������ͼ�ֵ" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> item[i].w >> item[i].v;
		item[i].p = item[i].w / item[i].v;
	}
	sort(item, item + n, cmp);
	double sum = 0.0;//װ�ؼ�ֵ�ܺ�
	for (int i = 0; i < n; i++)
	{
		if (c > item[i].w)//�������װ��
		{
			c -= item[i].w;
			sum += item[i].v;
		}
		else
		{
			sum += item[i].p * c;//����Ʒ�ָ�װ�롣���Լ۱ȳ���ʣ����װ�ص�����
			break;
		}
	}
	cout << "װ�صı����ֵ���Ϊ" << sum << endl;
	return 0;
}