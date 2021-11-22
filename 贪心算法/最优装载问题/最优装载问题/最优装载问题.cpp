#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#define N 1000005
using namespace std;

//贪心算法-最优装载问题
//有限容量，装载最大数量物品。核心思想是把物品递增排序，依次选取最小重量装载，即可达到最大数量。
double c;//最大容量
double w[N];//单个物品重量
int n;//物品总数
int m;//程序重复运行次数

void test01()
{
	//1.初始化场景
	cout << "请输入程序重复执行次数m:>";
	cin >> m;
	while (m--)//重复执行m次本算法
	{
		cout<<"请输入最大容载量c:>";
		cin >> c;
		cout << "请输入物品总数n:>";
		cin >> n;
		cout << "请依次输入每个物品的重量w:>" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
		}
		sort(w, w + n);//头文件algorithm的sort快速排序，参数是排序对象、排序对象+元素个数、排序方法cmp（没有则默认升序）
		
		//2.正式开始装载
		double temp = 0.0;//当前已装载容量
		int ans = 0;//当前已装载物品个数
		for (int i = 0; i < n; i++)
		{
			temp += w[i];//如果temp加过重量没有超上限，则ans个数+1，如果超了就不需要加，输出之前的ans作为最大物品数
			if (temp <= c)
				ans++;//因为只需要ans，而不需要temp这个重量的输出，所以temp加到超过容量也不用管
			else
				break;//超了直接退出循环即可
		}
		cout << "最多能装载物品个数ans为:" << ans << endl << endl;
	}
}
int main()
{
	test01();
	return 0;
}
//案例 重复次数m=2   容量c=15   个数n=7   
//物品：4  7  6  5  1  3  2
//理论最优装载 5 个