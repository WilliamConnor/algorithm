#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

//��ˮ��ҵ����-��̬�滮
int n;//��ҵ����
struct Node//��ҵ�ṹ��
{
	int a, b, c;//a-M1�ӹ���ʱ b-M2�ӹ���ʱ c-��ҵ���
}x[1500];
bool cmp(Node x, Node y)
{
	return min(x.a, y.b) < min(x.b, y.a);//�����Johnson����ʽ
}
int main()
{
	cout << "��������ҵ����" << endl;
	cin >> n;//������ҵ����
	for (int i = 1; i <= n; i++)//i=0���Ԫ��Ӧ�������ˣ���1��n
	{
		cout << "������ҵ" << i << "��M1��ʱ��M2��ʱ" << endl;
		cin >> x[i].a >> x[i].b;//������ҵ��ʱ
		x[i].c = i;//��ҵ������Զ���˳����ˣ����������
	}
	sort(x + 1, x + 1 + n, cmp);//����Johnson���򣬵�1��Ԫ�ز�������
	int ta = 0, tb = 0;//ta-��ǰ����M1���۵�ʱ�� tb-����M2���۵�ʱ��
	for (int i = 1; i <= n; i++)
	{
		ta += x[i].a;//ta������M1��ʱ�䣬���Ǹ���ҵ��aֱ�����
		tb = max(ta, tb) + x[i].b;//tb������M2��ʱ�䣬ѡ��ta��tb�������ټ��ϵ�ǰ��bʱ�䡣
		//ԭ�򣺢����M2�����ˣ�����M1û��ɣ���ҲҪ��M1�����������ֵ�M2�ӹ� �����M1����ˣ���M2��û�����һ���Ĺ������ǵ�M2��ɲ��ܼ�����һ�����������Ǿ���ȡ���ߵ�max
	}
	cout << "������ˮ���Ⱥ�ʱΪ��" << tb << endl;
	cout << "���ŵ���˳��Ϊ��";
	for (int i = 1; i <= n; i++)
	{
		 cout<< x[i].c;//���ŵ���˳��
	}
	return 0;
}
//���� ���룺4  5 6  12 2  4 14  8 7   ���:33  3124
//���� ���룺5  2 5  4 2  3 3  6 1  1 7    ���:19  51324