#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

//流水作业调度-动态规划
int n;//作业个数
struct Node//作业结构体
{
	int a, b, c;//a-M1加工耗时 b-M2加工耗时 c-作业编号
}x[1500];
bool cmp(Node x, Node y)
{
	return min(x.a, y.b) < min(x.b, y.a);//这就是Johnson不等式 让xy中a比较小的在前，b比较大的在后
}
int main()
{
	cout << "请输入作业总数" << endl;
	cin >> n;//输入作业总数
	for (int i = 1; i <= n; i++)//i=0这个元素应该留空了，从1到n
	{
		cout << "输入作业" << i << "的M1耗时和M2耗时" << endl;
		cin >> x[i].a >> x[i].b;//输入作业耗时
		x[i].c = i;//作业编号是自动按顺序给了，别多输入了
	}
	sort(x + 1, x + 1 + n, cmp);//按照Johnson排序，第1个元素不是数据
	int ta = 0, tb = 0;//ta-当前机器M1积累的时间 tb-机器M2积累的时间
	for (int i = 1; i <= n; i++)
	{
		ta += x[i].a;//ta即机器M1的时间，就是各作业的a直接相加
		tb = max(ta, tb) + x[i].b;//tb即机器M2的时间，选择ta和tb更大者再加上当前的b时间。
		//原因：①如果M2空闲了，但是M1没完成，那也要等M1完成这个货才轮到M2加工 ②如果M1完成了，但M2还没完成上一件的工作，那得M2完成才能加上下一件工作。于是就是取二者的max
	}
	cout << "最优流水调度耗时为：" << tb << endl;
	cout << "最优调度顺序为：";
	for (int i = 1; i <= n; i++)
	{
		 cout<< x[i].c;//最优调度顺序
	}
	return 0;
}
//案例 输入：4  5 6  12 2  4 14  8 7   输出:33  3142
//案例 输入：5  2 5  4 2  3 3  6 1  1 7    输出:19  51324

//johnson流程：以案例1为例，1和2不换，1和3不符合johnson，互换，换完后3到达一号位置，由3继续和4比，不换，一轮下来是3214
//之后是第二个位置也就是编号2，2和1不符合johnson，互换，之后第二个位置变成1了，由1继续和4比较，不换，二轮下来是3124
//之后第三个位置是2,2和4比较，换，三轮后是3142，完成