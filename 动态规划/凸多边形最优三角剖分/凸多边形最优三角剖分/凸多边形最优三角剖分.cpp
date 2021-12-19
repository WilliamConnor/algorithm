#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#define N 7
using namespace std;

//凸多边形最优三角剖分-动态规划-仍需理解
int weight[][N] = { {0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},{1,2,1,6,0,1},{4,3,4,2,1,0} };//凸多边形的权，随便给的，可以另外用cin输入
int MinWeightTriangulation(int n, int** t, int** s);//算最优三角剖分   n顶点数是N-1   t[i][j]储存从i到j的最优权重   s[i][j]储存以i,j作为顶点后选取的构成三角形的第三个顶点
void Traceback(int i, int j, int** s);//根据上面函数所得的s数组追溯选取了哪些顶点，i,j表示开始和结束顶点
int Weight(int a, int b, int c);//将三个顶点所连的三角形，其三边权相加

int main()
{
	//这里都是在new两个二维数组t和s
	int** t = new int* [N];
	int** s = new int* [N];
	for (int i = 0; i < N; i++)
	{
		t[i] = new int[N];
		s[i] = new int[N];
	}

	cout << "最优剖分值为:" << MinWeightTriangulation(N - 1, t, s) << endl;
	cout << "最优三角剖分选择的顶点:" << endl;
	Traceback(1, 5, s);
	return 0;
}

int Weight(int a, int b, int c)
{
	return weight[a][b] + weight[a][c] + weight[b][c];
}

int MinWeightTriangulation(int n, int** t, int** s)
{
	for (int i = 0; i <= n; i++)
	{
		t[i][i] = 0;//把自己到自己设为0
	}
	for (int r = 2; r <= n; r++)//i与j的差值
	{
		for (int i = 1; i <= n - r + 1; i++)//n - r + 1是最后一个r链的右边界
		{
			int j = i + r - 1;
			t[i][j] = t[i + 1][j] + Weight(i - 1, i, j);//k==i的情况
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				//将ij划分为A[i:k]*A[k+1][j]
				int u = t[i][k] + t[k + 1][j] + Weight(i - 1, k, j);
				if (u < t[i][j])
				{
					t[i][j] = u;
					s[i][j] = k;
				}
			}
		}
	}
	return t[1][N - 2];
}

void Traceback(int i, int j, int** s)
{
	if (i == j)//递归结束条件，ij中间没有再分割了
		return;
	Traceback(i, s[i][j], s);//从i到s[i][j]追溯，寻找每一段的最优"第三顶点"
	Traceback(s[i][j] + 1, j, s);//从s[i][j]+1到j
	cout << "三角剖分顶点:V" << i - 1 << "和V" << j << "和V" << s[i][j] << endl;//以i,j和s[i][j]所储存的相应顶点构成一个三角形
}