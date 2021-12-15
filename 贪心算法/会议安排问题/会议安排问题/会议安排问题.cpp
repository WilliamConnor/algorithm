#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
struct Meet
{
	int begin;//会议的开始时间、结束时间和编号
	int end;
	int num;
}meet[100];

class setMeet
{
public:
	void init();//初始化
	void solve();//解决方案
private:
	int n, cnt;//会议总数的安排的会议数
};

void setMeet::init()
{
	int b, e;
	cout << "请输入会议总数" << endl;
	cin >> n;
	cout << "输入会议的开始和结束时间" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> b >> e;
		meet[i].begin = b;
		meet[i].end = e;
		meet[i].num = i + 1;
	}
}
bool cmp(Meet x, Meet y)
{
	if (x.end == y.end)
	{
		return x.begin > y.begin;//优先将结束时间早的排前，end相等则开始begin时间晚的排前
	}
	return x.end < y.end;
}
void setMeet::solve()
{
	sort(meet, meet + n, cmp);
	cout << "会议排序如下"<<endl;
	cout << "会议编号 开始时间 结束时间" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << meet[i].num << " " << meet[i].begin << " " << meet[i].end << endl;
	}
	
	cout << "选择第" << meet[0].num << "号会议" << endl;//这3行先选出第一个会议
	cnt = 1;
	int last = meet[0].end;//将上一次选择的会议的结束时间作为last,只有下一个会议的开始时间晚于last才能安排，否则冲突
	for (int i = 1; i < n; i++)//对接下来的会议进行选择
	{
		if (meet[i].begin >= last)
		{
			cnt++;
			last = meet[i].end;
			cout << "选择了第" << meet[i].num << "个会议" << endl;
		}
	}

	cout << "最多可安排" << cnt << "个会议" << endl;
}

int main()
{
	setMeet m;
	m.init();//数据读入
	m.solve();//算法过程
	return 0;
}
