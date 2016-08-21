//경로찾기_11403
//160820

#include<iostream>
#include<cstdio>
using namespace std;

int n;
int arr[102][102];

int flag[102];


void dfs(int base, int k)
{
	flag[k] = 1;
	arr[base][k] = 1;

	if (base == k)
		return;

	if (k < base)//이미 완성된 케이스이다.
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[k][i] == 1)
			{
				arr[base][i] = 1;
				flag[i] = 1;
			}
		}
	}
	else
		for (int i = 1; i <= n; i++)
			if (arr[k][i] == 1&&flag[i]==0)
				dfs(base, i);
	
}


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

	//n은 정점갯수이다.
	//i부터시작해서 탐색하면됨
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1 & flag[j] == 0)
			{
				if (i == j)
					flag[j] = 1;
				else
					dfs(i, j);
			}
		}
		for (int k = 1; k <= n; k++)
			flag[k] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;

}