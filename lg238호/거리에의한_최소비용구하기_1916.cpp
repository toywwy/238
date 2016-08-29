/*

���� : �ּҺ�뱸�ϱ�
��ȣ : 1916
��¥ : 160829
��Ÿ : ������ ������ ã�Ƽ� ��� �������� �� �Ÿ��� �� �Ѹ��� ����� �ߴ�. �̰� ������ �����ϴ� ����� �ƴ϶�
���� ���� �ִ°Ÿ��� �������ִ� ����̴�. dp��� ó�� ����� �ϴ� ���̴�. ���� ȿ�� ���̴�.

*/

#include<iostream>
#include<vector>

#define N 1000
#define INF 100000002 // 1000*100000
using namespace std;

int n;
int bus;

int arr[N + 2][N + 2];
int visit[N + 2];
int dist[N + 2];

int mStart;
int mStop;

int main(void)
{

	cin >> n >> bus;
	
	//�ʱ�ȭ 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i != j)
				arr[i][j] = INF;

		dist[i] = INF;
	}

	//�Է�
	for (int i = 0; i < bus; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		
		if (arr[from][to] > weight)
			arr[from][to] = weight;
	}
	

	cin >> mStart >> mStop;

	visit[mStart] = 1;

	for (int i = 1; i <= n; i++)
		if (arr[mStart][i] != INF)
			dist[i] = arr[mStart][i];

	for (int i = 0; i < n; i++)
	{//n�� ���캸�� ���� ���� //������ n���ϱ� �ѹ��������� �ϳ��� ������ �����ϱ� ������
		int min = INF;
		int minIdx = 0;
		
		for (int j = 1; j <= n; j++)// �� ��������� ���� ������ bus������ ,, ������ n���� �����Ƿ�
		{
			if (visit[j] != true && min > dist[j])
			{
				min = dist[j];
				minIdx = j;
			}
		}//���� minIdx ���� //���� ����� �Ÿ��� �Ÿ��� �ѷ����� ���� ����. 
		
		visit[minIdx] = true;

		for (int j = 1; j <= n; j++)
		{
			if (dist[j] > ( min + arr[minIdx][j]))
				dist[j] = ( min+ arr[minIdx][j]);

		}

		if (minIdx == mStop) //���� �������� ���� �ִܰŸ� ã�°� �ƴϴϱ�.
			break;

	}
	
	cout << dist[mStop] << endl;

	return 0;
}