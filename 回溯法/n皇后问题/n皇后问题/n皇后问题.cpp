#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//n�ʺ�����-���ݷ�

//put_queen��x,y������ûʺ�ͬʱ����attack�����ʾ�ʺ��ܹ�������������
void put_queen(int x, int y, vector<vector<int>>& attack)
{
	//dx��dy�����������飬����֮���bfs����attack����
	static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
	static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
	attack[x][y] = 1;//�Ȱѵ�ǰ���궨Ϊ��ͻ����

	//������лʺ���Թ�����λ��
	for (int i = 1; i < attack.size(); i++)//bfs��ɢ
	{
		for (int j = 0; j < 8; j++)//ÿ��������8�����������һ��attack
		{
			int nx = x + i * dx[j];//nx��ny���ж�attack����������꣬�����˼��ξ�������չ�ڼ���
			int ny = y + i * dy[j];
			if (nx >= 0 && nx < attack.size() && ny >= 0 && ny < attack.size())
			{
				attack[nx][ny] = 1;//û��Խ�磬��attack���Ϊ1
			}
		}
	}
}

//���ݷ����ĺ���  k-��ǰ�� n-n�ʺ����� queen-�洢�Ļʺ�λ��
//attack-����λ�ñ��  solve-����n�ʺ�ȫ���ⷨ
void backtrack(int k, int n, vector<string>& queen,vector<vector<int>>&attack, vector<vector<string>>& solve)
{
	if (k == n)//��������ɵ����Ѿ��ﵽ����У����ʾ�ҵ���һ���
	{
		solve.push_back(queen);//���ý����solve����
		return;
	}

	for (int i = 0; i < n; i++)//i��������ÿһ��λ��
	{
		if (attack[k][i] == 0)//������λ�û����ܱ���������ѡ��˴����г���
		{
			vector<vector<int>>tmp = attack;//�ȱ���attack�Ա�����ָ�������һ�γ���
			queen[k][i] = 'Q';//��Ǹ�λ��ΪQѡȡ
			put_queen(k, i, attack);//�ʺ�������λ�ã���bfs����attack����
			backtrack(k + 1, n, queen, attack, solve);//��һ���Ѿ�������һ���ʺ���ôk+1����һ���ж���һ���ʺ�ŷ�(ͬһ�п϶����ܷ�2���ʺ�)

			//����һ��ѭ�����ݻ����󣬱�ʾҪ������ǰѡ���Qλ�ã����Ҫ�ָ�attack��queen����һ��
			attack = tmp;
			queen[k][i] = '.';
		}
	}
}


//��ά�����ʾ���нⷨ�����е�һάvector�ֱ��ʾһ�ֽⷨ�����е�string��ʾ�ýⷨ�Ļʺ��á�����string��ʾһ�У���.Q..�ȣ�vector�洢4��������string��ʾһ���ⷨ
vector<vector<string>>solveNQueens(int n)
{
	vector<string> queen;//����һ����Ļʺ����
	vector<vector<int>> attack;//attack���飬��ʾ����λ��
	vector<vector<string>> solve;//�������н⣬����������queen����

	for (int i = 0; i < n; i++)//��ʼ��attack��queen����
	{
		attack.push_back((std::vector<int>()));
		for (int j = 0; j < n; j++)
		{
			attack[i].push_back(0);//attack�������0
		}
		queen.push_back("");
		queen[i].append(n, '.');//queen�������.
	}
	backtrack(0, n, queen, attack, solve);//��ʼ���ݷ�
	return solve;//���ض�ά����洢�����н⣬solve��������queen��ÿ��queen��һ�ֽ�
}

int main()//����8�ʺ�
{
	vector<vector<string>> result;//result�������solve����Ľ��
	result = solveNQueens(8);

	//��ӡ8�ʺ�����ⷨ
	cout << "8�ʺ�ⷨ��Ϊ:" << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << "�ⷨ" << i + 1 << "Ϊ:" << endl;
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j].c_str() << endl;
		}
		cout << endl;
	}
	return 0;
}