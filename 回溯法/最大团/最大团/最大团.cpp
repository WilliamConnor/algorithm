#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define N 105
using namespace std;

//最大团问题-回溯法-(Maximum Clique Problem, MCP)-有bug
bool G[N][N];//图
bool x[N];//记录每一个节点是否选用
int bestx[N];//记录选用节点最好方案
int cnt = 0;//记录团节点数
int bestc;//记录最大团节点数
int n;//n-总节点数，作为限界条件

void MCP(int i)
{
	if (i > n)//到达界限说明是更好方案
	{
		bestc = cnt;
		for (int j = 1; j <= n; j++)
		{
			bestx[j] = x[j];//更新更好方案
		}
		return;
	}
	x[i] = 1;//先假定x[i] = 1，如果之后x[i] = 1则建立左子树。否则不选这个点，且建立右子树
	for (int j = 1; j < i; j++)//扫描当前团
	{
		if (x[j] == 1 && G[i][j] == 0)//如果当前点x[j]已选用，但是图 G[i][j]是不连通的，则flag为0表示不选这个节点，建立右子树
			x[i] = 0;
			break;
	}
	if (x[i])//选择这个节点
	{
		cnt++;//已选节点++
		MCP(i + 1);//进入下一层

		cnt--;//恢复计数cnt
	}
	x[i] = 0;//恢复节点为未选状态
	if (cnt + (n - i) > bestc)//如果当前已选节点+剩余可选节点>当前已知最大团最大节点数，则开右子树继续
	{
		x[i] = 0;
		MCP(i + 1);
	}
	return;//一个结束
}

int main()
{
	cout << "请输入顶点总数n:" << endl;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> G[i][j];
		}
	}

	MCP(1);
	cout << "最大团顶点数为:" << bestc << endl;
	cout << "最大团所选顶点为:";
	for (int i = 1; i <= n; i++)
	{
		if (bestx[i])
		{
			cout << i << " ";//以点的编号输出
		}
		//cout << bestx[i] << " ";//以0-1形式输出
	}
	return 0;
}
//案例 输入:5   0 1 0 1 1   1 0 1 0 1   0 1 0 0 1   1 0 0 0 1   1 1 1 1 0
//输出 1 1 0 0 1  (表示选择了1,2,5号顶点组成最大团)


//按边输入方法
//int main()
//{
//	int e, u, v;//e,u,v-边数，以及边的两个顶点
//	cout << "请输入顶点总数n:" << endl;
//	cin >> n;
//	cout << "请输入边总数e:" << endl;
//	cin >> e;
//	for (int i = 1; i <= e; i++)
//	{
//		cout << "请输入顶点" << i << endl;
//		cin >> u >> v;
//		G[u][v] = 1;
//	}
//	MCP(1);
//	cout << "最大团顶点数为:" << bestc << endl;
//	cout << "最大团所选顶点为:";
//	for (int i = 1; i <= n; i++)
//	{
//		cout << bestx[i] << " ";
//	}
//	return 0;
//}
////案例 输入:5 14  1 2  1 4  1 5  2 1  2 3  2 5  3 2  3 5  4 1  4 5  5 1  5 2  5 3  5 4 
////输出 1 1 0 0 1  (表示选择了1,2,5号顶点组成最大团)