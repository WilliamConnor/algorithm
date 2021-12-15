#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#define N 1005
using namespace std;

struct Item
{
	double w;//重量
	double v;//价格
	double p;//性价比，宝物可分割以装满容量
}item[N];
bool cmp(Item x, Item y)
{
	return x.p > y.p;//宝物按性价比递减排序
}
int main()
{
	int n;
	double c;
	cout << "请输入宝物数量n和承载力c" << endl;
	cin >> n >> c;
	cout << "请输入每个宝物的重量和价值" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> item[i].w >> item[i].v;
		item[i].p = item[i].w / item[i].v;
	}
	sort(item, item + n, cmp);
	double sum = 0.0;//装载价值总和
	for (int i = 0; i < n; i++)
	{
		if (c > item[i].w)//如果仍能装载
		{
			c -= item[i].w;
			sum += item[i].v;
		}
		else
		{
			sum += item[i].p * c;//将物品分割装入。即性价比乘以剩余能装载的容量
			break;
		}
	}
	cout << "装载的宝物价值最大为" << sum << endl;
	return 0;
}