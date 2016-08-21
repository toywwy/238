/*
	STL_MINHIP
	priority_queue를 min heap으로 사용할 수 있게된다.
	max heap의 경우에도 선언해줘야하는 것도 있다.

*/

#include <iostream> 
#include <functional> 
#include <queue> 
using namespace std;

class St {
public:
	St(int x, int y) : _x(x), _y(y) {}

	void print() { cout << "rect : " << _x << " * " << _y << " = " << _x * _y << endl; }

	// greater-than operator > 를 정의합니다. 이 operator는 min-heap을 정의할 때 쓰입니다. 
	// class 대신에 struct를 쓰는 것도 가능합니다. 
	bool operator > (const St& rhs) const { return _x*_y  > rhs._x * rhs._y; }

private:
	int _x, _y;
};

int main()
{
	// min-heap을 선언합니다. 
	priority_queue<St, vector<St>, greater<St> > q;
	q.push(St(1, 5));
	q.push(St(7, 6));
	q.push(St(1, 2));
	q.push(St(8, 2));

	while (!q.empty()) {
		St t = q.top();
		q.pop();

		t.print();  // print (1,2), (1,5), (8,2), (7,6) 
	}

	return 0;
}