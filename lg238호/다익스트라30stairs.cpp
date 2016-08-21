
//
//다익스트라
//http://59.23.113.171/30stair/dijkstra/dijkstra.php?pname=dijkstra
//160821
//

#include<iostream>
using namespace std;

int vertexCount;//정점의수
int lineCount;
int start;
class Path {
public:
	int from;
	int value;
	int flag;//왔다 갔으면 flag = 1 체크를 한다.
};

int arr[1002][1002] = { 0, };

Path *pathArr;

void recur(int level, int v, int value)// 최소의 정점이 들어온거다 5가 들어와서 흩 뿌려야한다.. //5는완료
{

	if (level <= vertexCount - 1)
	{
		//v에 들어온다.//다 흩뿌린다.
		for (int i = 1; i <= vertexCount; i++)//
		{//v에서 부터 정점 흩뿌리고 //0인지 아닌지로 판단해도될듯 0이 아니면 
			if (arr[v][i] != 0)// 5-> 4 가 0이아니라서 들어오게되고
			{//1인데
				int newOne = arr[v][i] + value; //

				if (newOne < pathArr[i].value)//새로운게 더 좋다면 갱신
				{
					pathArr[i].value = newOne;
					pathArr[i].from = v;
				}
			}
		}//모두 갱신을 해주고나서


		int min = 1000000002;
		int minIdx = 0;
		for (int i = 1; i <= vertexCount; i++)
		{
			if (pathArr[i].flag == 0)
			{
				if (pathArr[i].value < min)
				{
					min = pathArr[i].value;
					minIdx = i;
				}
			}
		}

		pathArr[minIdx].flag = 1;
		recur(level + 1, minIdx, pathArr[minIdx].value);
	}

}

void print(int v)
{
	if (pathArr[v].from != start)
	{
		print(pathArr[v].from);
		cout << pathArr[v].from << " ";
	}

}

int main(void)
{
	vertexCount = 0;//정점의수
	lineCount = 0;
	start = 0;

	cin >> vertexCount >> lineCount >> start;
	pathArr = new Path[vertexCount + 1];
	int from = 0;
	int to = 0;
	int val = 0;

	//어차피 이동간 값은 알고 있어 야지

	for (int i = 1; i <= vertexCount; i++)
	{
		Path path;
		path.from = 0;
		path.value = 0;
		path.flag = 0;
	}//처음시작할떄 이건 갖고가는게 좋겠다.




	for (int i = 0; i < lineCount; i++)//돌자 ...
	{
		cin >> from >> to >> val;
		arr[from][to] = val;
	}//배열에다가 길을 넣어놨다.

	for (int i = 1; i <= vertexCount; i++)
	{
		Path path;

		//시작 - > 시작 값은 고려 할 필요 없는데 , 아직 생각안해봄.
		if (arr[start][i] != 0)
		{
			path.from = start;
			path.value = arr[start][i];
			path.flag = 0;
		}
		else
		{
			path.from = 1;
			path.value = 1000000002;//무한대값들어감.
			path.flag = 0;
		}

		pathArr[i] = path;
	}

	pathArr[start].from = start;
	pathArr[start].value = 0;
	pathArr[start].flag = 0;


	//최소 부분인거 찾아서 그부분 넣는거부터

	int min = 1000000002;
	int minIdx = 0;

	for (int i = 1; i <= vertexCount; i++)
	{
		if (pathArr[i].value < min)
		{
			min = pathArr[i].value;
			minIdx = i;
		}
	}

	pathArr[minIdx].flag = 1;
	pathArr[minIdx].from = start;

	recur(1, minIdx, pathArr[minIdx].value);


	for (int i = 1; i <= vertexCount; i++)
	{
		//여기에서 from이 0이 될때 까지 출력해주는게 필요한데.


		cout << start << " ";//시작
		if (start != i)
		{
			print(i);//중간
			cout << i << endl;//도착
		}
		else
		{
			cout << endl;
		}

		/*cout << i << " = " << pathArr[i].value << endl;*/
	}

	return 0;
}

//값을 저장하고 갱신하는데 목적이 있다.

//정점이 커지는 순으로 출력한다...
//3--->4
//3--->5 이렇게만 계산하면 되는건가 그러면??


//입력의 첫 줄은 정점의 수 N(2 <= N <= 1000), 간선의 수 M(1 <= M <= 100, 000), 출발 정점 S 가 주어진다.
//다음 M 줄에는 Ai, Bi, Ci 가 주어진다.Ai 에서 Bi 로의 길이 있고 가는 Ci(1 <= Ci <= 100) 의 비용이 듣다.

//5 - 정점의수 8- 간선의수 1- 출발점
//1 2 7 다음줄 1->2 로 가충치 7