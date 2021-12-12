#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#define N 100//数组大小给够，不然给不出正确结果
using namespace std;

//棋盘覆盖-分治法
//tr、tc是当前处理区域左上角的行列  dr,dc是特殊点的位置  s是正方棋盘的长度，同时也是宽度
int tr, tc, dr, dc, s, tile = 1;//tile的赋值是第一个覆盖体的编号，可以为0、1或任意值，建议就1开始了
int board[N][N];//用于记录某一个位置填充的覆盖体是第几号
void chessBroad(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)//当棋盘为1X1的小格子时，无操作，直接返回
		return;
	int t = tile++;//每深入一层增加一个计数，t是覆盖体编号
	int s = size / 2;//行和列都对半分，棋盘分为4块
	//①左上角棋盘分治
	if (dr < tr + s && dc < tc + s)//当特殊点属于左上角范围内时
	{
		chessBroad(tr, tc, dr, dc, s);//正常递归即可
	}
	else//当特殊点不在范围内，需填充一个横跨三个范围的覆盖体
	{
		board[tr + s - 1][tc + s - 1] = t;//令左上角区域的最右下角格子填充
		chessBroad(tr, tc, tr + s - 1, tc + s - 1, s);//①最上角起始点tr、rc也做相应移动②同时在下一层递归中将横跨的填充点作为特殊点处理
	}
	//②右上角棋盘分治
	if (dr < tr + s && dc >= tc + s)
	{
		chessBroad(tr, tc + s, dr, dc, s);
	}
	else
	{
		board[tr + s - 1][tc + s] = t;
		chessBroad(tr, tc + s, tr + s - 1, tc + s, s);
	}
	//③左下角棋盘分治
	if (dr >= tr + s && dc < tc + s)
	{
		chessBroad(tr + s, tc, dr, dc, s);
	}
	else
	{
		board[tr + s][tc + s - 1] = t;
		chessBroad(tr + s, tc, tr + s, tc + s - 1, s);
	}	
	//④右下角棋盘分治
	if (dr >= tr + s && dc >= tc + s)
	{
		chessBroad(tr + s, tc + s, dr, dc, s);
	}
	else
	{
		board[tr + s][tc + s] = t;
		chessBroad(tr + s, tc + s, tr + s, tc + s, s);
	}
}

int main()
{
	cout << "请输入棋盘边长(s):" << endl;
	cin >> s;
	cout << "请输入特殊点位置(dr dc):" << endl;
	cin >> dr >> dc;

	chessBroad(0, 0, dr, dc, s);

	//输出结果
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			printf("%4d", board[i][j]);
			//cout << board[i][j] << " ";//需要学习C++输出统一宽度的方法
		}
		cout << endl;
	}
	return 0;
}
//案例1  输入:8 1 3   
/*输出:
 3   3   4   4   8   8   9   9
 3   2   4   0   8   7   7   9
 5   2   2   6  10  10   7  11
 5   5   6   6   1  10  11  11
13  13  14   1   1  18  19  19
13  12  14  14  18  18  17  19
15  12  12  16  20  17  17  21
15  15  16  16  20  20  21  21
*/
//案例2  输入:8 3 1   
/*输出:
   3   3   4   4   8   8   9   9
   3   2   2   4   8   7   7   9
   5   5   2   6  10  10   7  11
   5   0   6   6   1  10  11  11
  13  13  14   1   1  18  19  19
  13  12  14  14  18  18  17  19
  15  12  12  16  20  17  17  21
  15  15  16  16  20  20  21  21
*/

