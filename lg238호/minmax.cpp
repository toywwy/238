#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<string>

using namespace std;



list<int> l;
vector<int> v; 
vector<pair<int, int>> p;

int k = 0;
void insertNum(int n)
{
	l.push_back(n);
	v.push_back(n);
	p.push_back(make_pair(n,k++));
}


int main(void)
{

	insertNum(34);
	insertNum(2);
	insertNum(24);
	insertNum(11);
	insertNum(20);
	insertNum(5);
	insertNum(33);
	insertNum(1);


	auto a=  max_element(v.begin(), v.end());

	cout << *a << endl;

	int c= max(2,1323);

	cout << c << endl;

	string u1 = "long string"; 
	string v1 = "short";

	cout << min(u1, v1) << '\n'; 
	cout << min(u1, v1, 
		[](string u1, string v1) { return u1.size() < v1.size();
	}) << '\n';

	//람다 좀 잘쓰면 좋을 것 같다 comp 구현할떄

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << endl;
	
	sort(v.begin(), v.end(), [](int a, int b) {return a < b; });


	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << endl;
	cout << endl;


	for (int i = 0; i < p.size(); i++)
		cout << p[i].first << " , " << p[i].second << endl;
	cout << endl;

	sort(p.begin(), p.end(), [](pair<int,int> a, pair<int, int> b) {
	
		return a.first < b.first;
	});

	

	for (int i = 0; i < p.size(); i++)
		cout << p[i].first<<" , "<<p[i].second <<endl;
	cout << endl;
	//sort 진짜 만능인것같다.


	auto pai= minmax_element(v.begin(), v.end());//-1을 해야 찾을수가있구나...


	int pa1 = pai.first[0];
	int pa2 = pai.second[0];

	cout << pa1 << " , " << pa2 << endl;
	return 0;
}