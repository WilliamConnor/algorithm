#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>

//��pq��STL���У����Զ���Ԫ�ؽ���������С���ڶ�β
priority_queue<int, vector<int>, greater<int>>pq;//�������ͣ�������ʽ�����򷽷�
int n = 0;
using namespace std;

int main()
{
	int val;
	while (!pq.empty())//������в��գ��������
		pq.pop();
	cin >> n;//����Ҫ���ɹ����������ܽ����
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		pq.push(val);//һ��һ������push�����У������Զ�����
	}
	while (pq.size() > 1)//ֻҪ���еĴ�Сû��ֻʣһ��ֵ���ͽ��й���������
	{
		int x1 = pq.top();
		pq.pop();

		int x2 = pq.top();
		pq.pop();

		pq.push(x1 + x2);//������������ġ��ֱ�ȡ��������С������ֵ����Ӻ�push�ض��У����л��Զ�����
	}
	if (pq.size() == 1)
		cout << pq.top() << endl;//����ȷʵֻʣһ���ڵ����ӡ������
	return 0;
}
