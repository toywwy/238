
/*
문제 : 경로찾기
문제 번호: 11403
풀이법 : BFS
날짜 : 160821
기타 : BFS인데 2차원으로 생각하는 방식이 아니라 어차피 하나하나씩 정점을 해결하기 떄문에
1차원으로 각각의 케이스만 ans에 담으면된다. 다른 그런거 이용하지 않는다.
*/


#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int n;
int arr[102][102];
int ans[102][102];

int flag[102];

queue<int> q;

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int m = 0;
			scanf("%d", &m);
			arr[i][j] = m;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		q.push(i);

		xhile (!q.empty())
		{
			int a = q.front();
			q.pop();

			for (int j = 1; j <= n; j++)
			{
				if (arr[a][j] == 1 && ans[i][j]!=1)
				{
					q.push(j);
					ans[i][j] = 1;
				}
			}
		}
	}



	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}

	



	return 0;
}