#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define N 20
using namespace std;

int n, m;//n是图的顶点数，m是颜色数
int a = 1, b = 1, cnt = 0;//a,b初值1可能方便判断
int G[N][N];//图的邻接矩阵
int color[N];//着色图

//判断是否可以着色
bool ok(int i)
{
	for (int j = 0; j <= n; j++)
	{
		if (G[i][j] && color[i] == color[j])//如果ij联通且颜色相等，则不可着色
			return false;
	}
	return true;
}

//回溯法判断m着色
void backtrack(int num)//参数是当前要着色的点
{
	if (num > n)//如果当前点号大于总点数，说明着色完成，把结果输出
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d", color[i]);//按照顶点顺序依次输出其相应的颜色编号
		}
		cnt++;
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= m; i++)//对最多m种颜色逐个着色
		{
			color[num] = i;//第num个顶点着色i号
			if (ok(num))//要判断是否可着色，即此处着色不会和相邻点为同一颜色
			{
				backtrack(num + 1);//继续下一个顶点的着色
			}
			color[num] = 0;//从深层返回就说明着色失败，换下一个颜色，在这之前先把color赋回0值
		}
	}
}


int main()
{
	memset(G, 0, sizeof(G));//memset让元素全为0，参数列表：对象，填充物，对象大小
	memset(color, 0, sizeof(color));
	scanf("%d%d", &n, &m);
	while (scanf("%d%d", &a, &b) != EOF && a != 0 && b != 0)//似乎是从文件读取，并将图的关系构成
	{
		G[a][b] = 1;
		G[b][a] = 1;
	}
	backtrack(1);//从第1个颜色开始判断
	printf("%d", cnt);//大概是1表示着色成功，0表示失败
	return 0;
}