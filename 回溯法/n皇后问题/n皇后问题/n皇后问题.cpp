#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//n皇后问题-回溯法

//put_queen在x,y坐标放置皇后，同时更新attack数组表示皇后能攻击的所有坐标
void put_queen(int x, int y, vector<vector<int>>& attack)
{
	//dx和dy两个方向数组，方便之后的bfs更新attack数组
	static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
	static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
	attack[x][y] = 1;//先把当前坐标定为冲突坐标

	//标记所有皇后可以攻击的位置
	for (int i = 1; i < attack.size(); i++)//bfs扩散
	{
		for (int j = 0; j < 8; j++)//每次往四周8个方向各更新一次attack
		{
			int nx = x + i * dx[j];//nx和ny是判断attack数组的新坐标，遍历了几次就往外拓展第几个
			int ny = y + i * dy[j];
			if (nx >= 0 && nx < attack.size() && ny >= 0 && ny < attack.size())
			{
				attack[nx][ny] = 1;//没有越界，则attack标记为1
			}
		}
	}
}

//回溯法核心函数  k-当前行 n-n皇后问题 queen-存储的皇后位置
//attack-攻击位置标记  solve-储存n皇后全部解法
void backtrack(int k, int n, vector<string>& queen,vector<vector<int>>&attack, vector<vector<string>>& solve)
{
	if (k == n)//当处理完成的行已经达到最大行，则表示找到了一组解
	{
		solve.push_back(queen);//将该解存入solve数组
		return;
	}

	for (int i = 0; i < n; i++)//i遍历该行每一个位置
	{
		if (attack[k][i] == 0)//如果这个位置还不能被攻击，则选择此处进行尝试
		{
			vector<vector<int>>tmp = attack;//先备份attack以便后续恢复进行下一次尝试
			queen[k][i] = 'Q';//标记该位置为Q选取
			put_queen(k, i, attack);//皇后打入这个位置，并bfs更新attack数组
			backtrack(k + 1, n, queen, attack, solve);//这一行已经尝试了一个皇后，那么k+1到下一行判断下一个皇后放法(同一行肯定不能放2个皇后)

			//从下一层循环回溯回来后，表示要舍弃当前选择的Q位置，因此要恢复attack和queen到上一步
			attack = tmp;
			queen[k][i] = '.';
		}
	}
}


//二维数组表示所有解法，其中的一维vector分别表示一种解法，其中的string表示该解法的皇后布置。即：string表示一行，如.Q..等，vector存储4个这样的string表示一个解法
vector<vector<string>>solveNQueens(int n)
{
	vector<string> queen;//保存一个解的皇后放置
	vector<vector<int>> attack;//attack数组，表示攻击位置
	vector<vector<string>> solve;//保存所有解，即保存所有queen数组

	for (int i = 0; i < n; i++)//初始化attack和queen数组
	{
		attack.push_back((std::vector<int>()));
		for (int j = 0; j < n; j++)
		{
			attack[i].push_back(0);//attack数组打入0
		}
		queen.push_back("");
		queen[i].append(n, '.');//queen数组打入.
	}
	backtrack(0, n, queen, attack, solve);//开始回溯法
	return solve;//返回二维数组存储了所有解，solve内有所有queen，每个queen是一种解
}

int main()//测试8皇后
{
	vector<vector<string>> result;//result数组接收solve数组的结果
	result = solveNQueens(8);

	//打印8皇后问题解法
	cout << "8皇后解法数为:" << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << "解法" << i + 1 << "为:" << endl;
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j].c_str() << endl;
		}
		cout << endl;
	}
	return 0;
}