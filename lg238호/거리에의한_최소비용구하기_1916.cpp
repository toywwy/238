/*

문제 : 최소비용구하기
번호 : 1916
날짜 : 160829
기타 : 원래는 정점을 찾아서 모든 정점에서 또 거리르 다 뿌리는 방식을 했다. 이건 정점을 저장하는 방식이 아니라
내가 갈수 있는거리를 가지고있는 방식이다. dp방식 처럼 사용을 하는 것이다. 제일 효율 적이다.

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
	
	//초기화 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i != j)
				arr[i][j] = INF;

		dist[i] = INF;
	}

	//입력
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
	{//n번 살펴보면 답이 나옴 //정점이 n개니까 한번돌때마다 하나의 정점을 선택하기 때문에
		int min = INF;
		int minIdx = 0;
		
		for (int j = 1; j <= n; j++)// 각 정점들로의 간선 갯수는 bus개지만 ,, 정점은 n개가 있으므로
		{
			if (visit[j] != true && min > dist[j])
			{
				min = dist[j];
				minIdx = j;
			}
		}//정점 minIdx 선택 //제일 가까운 거리인 거리를 뿌려놓고 정점 고른다. 
		
		visit[minIdx] = true;

		for (int j = 1; j <= n; j++)
		{
			if (dist[j] > ( min + arr[minIdx][j]))
				dist[j] = ( min+ arr[minIdx][j]);

		}

		if (minIdx == mStop) //모든거 정점으로 가는 최단거리 찾는게 아니니까.
			break;

	}
	
	cout << dist[mStop] << endl;

	return 0;
}