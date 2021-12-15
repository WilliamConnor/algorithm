#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>

//此pq是STL队列，会自动对元素进行排序，最小的在队尾
priority_queue<int, vector<int>, greater<int>>pq;//数据类型，数组形式，排序方法
int n = 0;
using namespace std;

int main()
{
	int val;
	while (!pq.empty())//如果队列不空，则先清空
		pq.pop();
	cin >> n;//输入要生成哈夫曼树的总结点数
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		pq.push(val);//一个一个将数push进队列，排序自动进行
	}
	while (pq.size() > 1)//只要队列的大小没有只剩一个值，就进行哈夫曼操作
	{
		int x1 = pq.top();
		pq.pop();

		int x2 = pq.top();
		pq.pop();

		pq.push(x1 + x2);//哈夫曼编码核心。分别取出队列最小的两个值，相加后push回队列，队列会自动排序
	}
	if (pq.size() == 1)
		cout << pq.top() << endl;//队列确实只剩一个节点则打印这个结果
	return 0;
}
