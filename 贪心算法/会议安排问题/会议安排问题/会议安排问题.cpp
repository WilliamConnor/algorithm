#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
struct Meet
{
	int begin;//����Ŀ�ʼʱ�䡢����ʱ��ͱ��
	int end;
	int num;
}meet[100];

class setMeet
{
public:
	void init();//��ʼ��
	void solve();//�������
private:
	int n, cnt;//���������İ��ŵĻ�����
};

void setMeet::init()
{
	int b, e;
	cout << "�������������" << endl;
	cin >> n;
	cout << "�������Ŀ�ʼ�ͽ���ʱ��" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> b >> e;
		meet[i].begin = b;
		meet[i].end = e;
		meet[i].num = i + 1;
	}
}
bool cmp(Meet x, Meet y)
{
	if (x.end == y.end)
	{
		return x.begin > y.begin;//���Ƚ�����ʱ�������ǰ��end�����ʼbeginʱ�������ǰ
	}
	return x.end < y.end;
}
void setMeet::solve()
{
	sort(meet, meet + n, cmp);
	cout << "������������"<<endl;
	cout << "������ ��ʼʱ�� ����ʱ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << meet[i].num << " " << meet[i].begin << " " << meet[i].end << endl;
	}
	
	cout << "ѡ���" << meet[0].num << "�Ż���" << endl;//��3����ѡ����һ������
	cnt = 1;
	int last = meet[0].end;//����һ��ѡ��Ļ���Ľ���ʱ����Ϊlast,ֻ����һ������Ŀ�ʼʱ������last���ܰ��ţ������ͻ
	for (int i = 1; i < n; i++)//�Խ������Ļ������ѡ��
	{
		if (meet[i].begin >= last)
		{
			cnt++;
			last = meet[i].end;
			cout << "ѡ���˵�" << meet[i].num << "������" << endl;
		}
	}

	cout << "���ɰ���" << cnt << "������" << endl;
}

int main()
{
	setMeet m;
	m.init();//���ݶ���
	m.solve();//�㷨����
	return 0;
}
