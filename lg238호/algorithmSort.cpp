/*
algorithm , sort 응용 cmp
그냥 cmp 에다가 bool으로만 제공하면 그냥 배열이던, 구조체던, vector 이런거 다 정렬이 가능하다 ...진짜 좋다

만약에 queue array가 아니더라도
vector<Queue> queue;
이렇더라도 똑같이 적용이된다.정말좋다.
*/



#include<iostream>
#include<queue>
#include<algorithm>


using namespace std;

vector<pair<int, int>> v;


bool cmp(pair<int,int> p1, pair<int,int> p2)
{
	//어쩃든 대소만 제공하면 알아서 정렬해줌..
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
그냥 cmp 에다가 bool으로만 제공하면 그냥 배열이던 , 구조체던, vector 이런거 다 정렬이 가능하다 ...진짜 좋다

만약에 queue array가 아니더라도
vector<Queue> queue;
이렇더라도 똑같이 적용이된다. 정말좋다.


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
//어쩃든 대소만 제공하면 알아서 정렬해줌..
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