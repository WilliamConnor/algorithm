#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

using namespace std;

////多机调度问题-排序仍有bug
////工作时间按大到小排序，每次将当前最大时间的工作安排到当前已排时间总和最小的机器上
//bool cmp(int a, int b)
//{
//	return a > b;
//}
//int main()
//{
//	int n = 7;//作业数量
//	int m = 3;//机器数量
//	int time[8] = { 0,2,14,4,16,6,5,3 };//每个工作所耗时间
//	int MachineCount[4] = { 0 };//每台机器上安排作业数量
//	int MachineJobs[4][8] = { {0} };//每台机器安排了哪些工作
//	int MachineTime[4] = { 0 };//每台机器安排的总时间
//	//数组第0个下标取0，数组从1开始放数据，方便一一对应
//
//	sort(time + 1, time + n, cmp);//时间递减排序，先看最大的，注意因为[0]空余，所以数组从time+1排序。(默认是递增，这里用cmp来实现递减)
//	//循环执行工作分配语句，由大到小依次安排每一件工作
//	for(int i=1;i<=n;i++)
//	{
//		//选取当前已安排总时间最小的机器数组下标k
//		int k = MachineTime[0];
//		for (int j = 1; j <= m; j++)
//		{
//			if (MachineTime[j] < MachineTime[0])
//				k = j;
//		}
//		//该机器作业量+1
//		MachineCount[k]++;
//		//该机器总时间增加这个作业i的时间
//		MachineTime[k] += time[i];
//		//该机器安排作业的二维数组增加相应内容，行是相应机器，列是相应作业，0-1表示选择或没选
//		MachineJobs[k][i] = 1;
//	}
//	//完成，MachineJobs[4][8]就是dp[][]动态规划表
//	//打印每个机器安排的工作序号
//	for (int j = 1; j <= m; j++)
//	{
//		cout << "第" << j << "台机器安排的工作：";
//		for (int i = 1; i <= n; i++)
//		{
//			if (MachineJobs[j][i] == 1)
//				cout << i<<" ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	//打印每个机器安排总时长
//	for (int j = 1; j <= m; j++)
//	{
//		cout << "第" << j << "台机器安排的总时长：" << MachineTime[j] << endl;;
//	}
//
//
//	return 0;
//}



//网络cpoy-1
//某工厂有n个独立的作业，由m台相同的机器进行加工处理。作业i所需的加工时间为ti，任何作业在被处理时不能中断，也不能进行拆分处理。
//现厂长请你给他写一个程序：算出n个作业由m台机器加工处理的较短时间。
//输入第一行T（1 < T < 100)表示有T组测试数据。每组测试数据的第一行分别是整数n，m（1 <= n <= 10000，1 <= m <= 100），
//接下来的一行是n个整数ti（1 <= t <= 100)。
// 输出所需的较短时间。（提示：不一定是最优解）
//样例输入:2 2 2 1 5 6 3 2 5 13 15 16 20    样例输出:5 28
//样例输入：1 7 3 2 14 4 16 6 5 3    输出：17
int main()
{
    //程序重复t次，n个独立的作业，m台相同的机器，作业i所需的加工时间为ti
    int t, n, m, ti[10000];
    scanf("%d", &t);
    while (t--)
    {
        int i, j, co[100] = { 0 }, max, k, min;
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            scanf("%d", &ti[i]);
        for (i = 0; i < n; i++) //对时间进行从大到小的排序
        {
            for (k = i, max = ti[i], j = i; j < n; j++)
                if (ti[j] > max)
                {
                    max = ti[j];
                    k = j;
                }
            ti[k] = ti[i];
            ti[i] = max;
        }
        if (n <= m) //当机器数目多时，直接输出最大时间，极为所需最少时间
        {
            printf("%d\n", ti[0]);
            continue;
        }
        else //机器数目少时
        {
            for (i = 0; i < n; i++) //思路：总是把任务交给当前最空闲的机器
            {
                min = co[0];
                for (k = 0, j = 1; j < m; j++)
                    if (co[j] < min)
                    {
                        min = co[j];
                        k = j;
                    }
                co[k] += ti[i];
            }
        }
        max = co[0];
        for (i = 1; i < m; i++)
            if (co[i] > max)
                max = co[i];
        printf("%d\n", max);
    }
    return 0;
}