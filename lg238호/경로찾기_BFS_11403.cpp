
/*
���� : ���ã��
���� ��ȣ: 11403
Ǯ�̹� : BFS
��¥ : 160821
��Ÿ : BFS�ε� 2�������� �����ϴ� ����� �ƴ϶� ������ �ϳ��ϳ��� ������ �ذ��ϱ� ������
1�������� ������ ���̽��� ans�� ������ȴ�. �ٸ� �׷��� �̿����� �ʴ´�.
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