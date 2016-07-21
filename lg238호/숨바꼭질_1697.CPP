#include<iostream>
#include<cstdio>
#include <cmath>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int a, b;

	cin >> a >> b;

	vector<int> visit(200000);//이렇게만 하면 안전한 거리를 위지 할 수 있따...
	queue<int> q;//q처럼 사용을하자.

	q.push(a);
	visit[a] = 1;

	int cnt = 0;
	
	bool result = false;

	while (!q.empty())
	{
		//3가지 경우를 모두 Queue에다가 넣는다 그리고 가장 가까운 거리르 항상유지한다.
		int num = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{// 뺸다 // 범위 체크하자.
				if (num - 1 >= 0)
				{
					if (visit[num - 1] == 0)
					{
						visit[num - 1] = visit[num] + 1;
						q.push(num - 1);
						if (num - 1 == b)
						{ 
							result = true; 
							cnt = visit[num];

							break;
						}
					}
				}
			}
			else if (i == 1)
			{//더한다 ... 범위체크해야함..
				if (num + 1 <= b)
				{
					if (visit[num + 1] == 0)
					{
						visit[num + 1] = visit[num]+1;
						q.push(num + 1);

						if (num + 1 == b)
						{
							result = true;
							cnt = visit[num];

							break;
						}
					}
				}
			}
			else//i==2;
			{//곱한다 최소값과 범위 체크가 꼭 필요한 시점이다.
				if (num * 2 < b *2 +1)
				{ 
					if (visit[num * 2] ==0)
					{
						visit[num * 2] = visit[num] + 1;
						q.push(num * 2);

						if (num * 2 == b)
						{
							result = true;
							cnt = visit[num];
							break;
						}
					}
				}
			}
		}

		if (result)
			break;
	}

	cout << cnt << endl;

	return 0;
}