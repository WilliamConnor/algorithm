#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#define N 100//�����С��������Ȼ��������ȷ���
using namespace std;

//���̸���-���η�
//tr��tc�ǵ�ǰ�����������Ͻǵ�����  dr,dc��������λ��  s���������̵ĳ��ȣ�ͬʱҲ�ǿ��
int tr, tc, dr, dc, s, tile = 1;//tile�ĸ�ֵ�ǵ�һ��������ı�ţ�����Ϊ0��1������ֵ�������1��ʼ��
int board[N][N];//���ڼ�¼ĳһ��λ�����ĸ������ǵڼ���
void chessBroad(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)//������Ϊ1X1��С����ʱ���޲�����ֱ�ӷ���
		return;
	int t = tile++;//ÿ����һ������һ��������t�Ǹ�������
	int s = size / 2;//�к��ж��԰�֣����̷�Ϊ4��
	//�����Ͻ����̷���
	if (dr < tr + s && dc < tc + s)//��������������ϽǷ�Χ��ʱ
	{
		chessBroad(tr, tc, dr, dc, s);//�����ݹ鼴��
	}
	else//������㲻�ڷ�Χ�ڣ������һ�����������Χ�ĸ�����
	{
		board[tr + s - 1][tc + s - 1] = t;//�����Ͻ�����������½Ǹ������
		chessBroad(tr, tc, tr + s - 1, tc + s - 1, s);//�����Ͻ���ʼ��tr��rcҲ����Ӧ�ƶ���ͬʱ����һ��ݹ��н�����������Ϊ����㴦��
	}
	//�����Ͻ����̷���
	if (dr < tr + s && dc >= tc + s)
	{
		chessBroad(tr, tc + s, dr, dc, s);
	}
	else
	{
		board[tr + s - 1][tc + s] = t;
		chessBroad(tr, tc + s, tr + s - 1, tc + s, s);
	}
	//�����½����̷���
	if (dr >= tr + s && dc < tc + s)
	{
		chessBroad(tr + s, tc, dr, dc, s);
	}
	else
	{
		board[tr + s][tc + s - 1] = t;
		chessBroad(tr + s, tc, tr + s, tc + s - 1, s);
	}	
	//�����½����̷���
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
	cout << "���������̱߳�(s):" << endl;
	cin >> s;
	cout << "�����������λ��(dr dc):" << endl;
	cin >> dr >> dc;

	chessBroad(0, 0, dr, dc, s);

	//������
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			printf("%4d", board[i][j]);
			//cout << board[i][j] << " ";//��ҪѧϰC++���ͳһ��ȵķ���
		}
		cout << endl;
	}
	return 0;
}
//����1  ����:8 1 3   
/*���:
 3   3   4   4   8   8   9   9
 3   2   4   0   8   7   7   9
 5   2   2   6  10  10   7  11
 5   5   6   6   1  10  11  11
13  13  14   1   1  18  19  19
13  12  14  14  18  18  17  19
15  12  12  16  20  17  17  21
15  15  16  16  20  20  21  21
*/
//����2  ����:8 3 1   
/*���:
   3   3   4   4   8   8   9   9
   3   2   2   4   8   7   7   9
   5   5   2   6  10  10   7  11
   5   0   6   6   1  10  11  11
  13  13  14   1   1  18  19  19
  13  12  14  14  18  18  17  19
  15  12  12  16  20  17  17  21
  15  15  16  16  20  20  21  21
*/

