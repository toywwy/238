/*
algorithm , sort ���� cmp
�׳� cmp ���ٰ� bool���θ� �����ϸ� �׳� �迭�̴�, ����ü��, vector �̷��� �� ������ �����ϴ� ...��¥ ����

���࿡ queue array�� �ƴϴ���
vector<Queue> queue;
�̷����� �Ȱ��� �����̵ȴ�.��������.
*/



#include<iostream>
#include<queue>
#include<algorithm>


using namespace std;

vector<pair<int, int>> v;


bool cmp(pair<int,int> p1, pair<int,int> p2)
{
	//��� ��Ҹ� �����ϸ� �˾Ƽ� ��������..
	return p1.second < p2.second;
}


int main(void)
{

	v.push_back(make_pair(12, 3));
	v.push_back(make_pair(2, 2));
	v.push_back(make_pair(13, 1));
	v.push_back(make_pair(1, 5));
	v.push_back(make_pair(3, 0));

	sort(v.begin(), v.end(), cmp);

	for (auto itr = v.begin(); itr != v.end(); itr++)
	{

		cout << itr->first << " , " << itr->second << endl;
	}


	return 0;
}


/*
�׳� cmp ���ٰ� bool���θ� �����ϸ� �׳� �迭�̴� , ����ü��, vector �̷��� �� ������ �����ϴ� ...��¥ ����

���࿡ queue array�� �ƴϴ���
vector<Queue> queue;
�̷����� �Ȱ��� �����̵ȴ�. ��������.


#include<iostream>
#include<algorithm>

using namespace std;

class Queue
{
public :
int a;
int b;

Queue()
{}
Queue( int a, int b)
{
this->a = a;
this->b = b;
}
};

Queue * queue = new Queue[100];


bool cmp(Queue qu1 , Queue qu2 )
{
//��� ��Ҹ� �����ϸ� �˾Ƽ� ��������..
return qu1.a < qu2.a;
}

int main(void )
{

int arr[] = { 23,4,34,32,45,132,35,3,2,1 };

int idx = 0;

for ( int i = 0; i < 10; i++)
{
Queue q(arr[i], i);
queue[i] = q;
}


for ( int i = 0; i < 10; i++)
cout << queue[i].a << " ";
cout << endl;

sort(queue,queue+10, cmp);

for ( int i = 0; i < 10; i++)
cout <<queue[i].a <<" ";
cout << endl;


return 0;
}





*/