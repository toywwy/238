
//
//���ͽ�Ʈ��
//http://59.23.113.171/30stair/dijkstra/dijkstra.php?pname=dijkstra
//160821
//

#include<iostream>
using namespace std;

int vertexCount;//�����Ǽ�
int lineCount;
int start;
class Path {
public:
	int from;
	int value;
	int flag;//�Դ� ������ flag = 1 üũ�� �Ѵ�.
};

int arr[1002][1002] = { 0, };

Path *pathArr;

void recur(int level, int v, int value)// �ּ��� ������ ���°Ŵ� 5�� ���ͼ� �� �ѷ����Ѵ�.. //5�¿Ϸ�
{

	if (level <= vertexCount - 1)
	{
		//v�� ���´�.//�� ��Ѹ���.
		for (int i = 1; i <= vertexCount; i++)//
		{//v���� ���� ���� ��Ѹ��� //0���� �ƴ����� �Ǵ��ص��ɵ� 0�� �ƴϸ� 
			if (arr[v][i] != 0)// 5-> 4 �� 0�̾ƴ϶� �����Եǰ�
			{//1�ε�
				int newOne = arr[v][i] + value; //

				if (newOne < pathArr[i].value)//���ο�� �� ���ٸ� ����
				{
					pathArr[i].value = newOne;
					pathArr[i].from = v;
				}
			}
		}//��� ������ ���ְ���


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
	vertexCount = 0;//�����Ǽ�
	lineCount = 0;
	start = 0;

	cin >> vertexCount >> lineCount >> start;
	pathArr = new Path[vertexCount + 1];
	int from = 0;
	int to = 0;
	int val = 0;

	//������ �̵��� ���� �˰� �־� ����

	for (int i = 1; i <= vertexCount; i++)
	{
		Path path;
		path.from = 0;
		path.value = 0;
		path.flag = 0;
	}//ó�������ҋ� �̰� �����°� ���ڴ�.




	for (int i = 0; i < lineCount; i++)//���� ...
	{
		cin >> from >> to >> val;
		arr[from][to] = val;
	}//�迭���ٰ� ���� �־����.

	for (int i = 1; i <= vertexCount; i++)
	{
		Path path;

		//���� - > ���� ���� ��� �� �ʿ� ���µ� , ���� �������غ�.
		if (arr[start][i] != 0)
		{
			path.from = start;
			path.value = arr[start][i];
			path.flag = 0;
		}
		else
		{
			path.from = 1;
			path.value = 1000000002;//���Ѵ밪��.
			path.flag = 0;
		}

		pathArr[i] = path;
	}

	pathArr[start].from = start;
	pathArr[start].value = 0;
	pathArr[start].flag = 0;


	//�ּ� �κ��ΰ� ã�Ƽ� �׺κ� �ִ°ź���

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
		//���⿡�� from�� 0�� �ɶ� ���� ������ִ°� �ʿ��ѵ�.


		cout << start << " ";//����
		if (start != i)
		{
			print(i);//�߰�
			cout << i << endl;//����
		}
		else
		{
			cout << endl;
		}

		/*cout << i << " = " << pathArr[i].value << endl;*/
	}

	return 0;
}

//���� �����ϰ� �����ϴµ� ������ �ִ�.

//������ Ŀ���� ������ ����Ѵ�...
//3--->4
//3--->5 �̷��Ը� ����ϸ� �Ǵ°ǰ� �׷���??


//�Է��� ù ���� ������ �� N(2 <= N <= 1000), ������ �� M(1 <= M <= 100, 000), ��� ���� S �� �־�����.
//���� M �ٿ��� Ai, Bi, Ci �� �־�����.Ai ���� Bi ���� ���� �ְ� ���� Ci(1 <= Ci <= 100) �� ����� ���.

//5 - �����Ǽ� 8- �����Ǽ� 1- �����
//1 2 7 ������ 1->2 �� ����ġ 7