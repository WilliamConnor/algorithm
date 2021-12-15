#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

int s = 100;//路程总长

void func(int x[], int n, int dist, int flag[])//贪心不是递归，这里是把参数陈列而已，不是作为递归条件
{//int x[]是每个加油站起点距离，n为加油站总数，dist为车辆满油能行驶距离，flag是记录选取的加油站分别距离起点多远

	//这里先判断是否存在汽车无法到达终点的可能，如果出现两个加油站之间的距离超出车辆满油行驶距离，则之间输出无结果
	for (int i = 1; i < n; i++)
	{
		if (dist < (x[i] - x[i - 1]))
		{
			cout << "汽车无法到达终点！" << endl;
			return;
		}
	}
	//如果汽车可以到达终点，即依次判断每一个加油站处汽车不加油能不能到下一个地点，不能则加油
	int j = 1, k = 0, sum = dist;//j表示选取的加油站数量，k是当前加油站，sum表示已走的总路程
	while (sum < s)//没走完路程就增加
	{
		for (int i = k; i < n; i++)//如果一次汽车路程中间可以经过多个加油站，则只选最远的那个加油站才加油，每次i由k决定就是为了跳过中间加油站
		{
			if (x[i] > sum)//如果汽车能开到下一个加油站不需要在当前加油站加油，直到汽车到不了下一个
			{
				flag[j] = x[i - 1];//记录下加油的这个位置是距离起点多远的那个加油站
				j++;
				sum = x[i - 1] + dist;//同时sum就表示当前的这个加油站的位置，加上汽车还能前进的距离作为汽车行驶总距离
				k = i;//让下一次的加油站考量跳过中间的加油站，直接从k开始
				break;
			}
		}
	}

}

int main()
{
	int n = 0;
	cout << "请输入加油站的个数" << endl;
	cin >> n;
	int* x = new int[n];//以给定的n创建不浪费空间的数组
	int* flag = new int[n];
	cout << "请输入每个加油站分别距离出发点的距离" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	int dist = 0;
	cout << "请输入汽车加满油能行驶的里程" << endl;
	cin >> dist;
	func(x, n, dist, flag);//调用函数
	cout << "分别在以下位置的加油站进行了加油" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << flag[i];//flag实际上是记录了停靠的加油站分别距离起点的位置
	}
	delete[] x;//注意释放自创数组，而且是delete[]形式
	delete[] flag;
	return 0;
}