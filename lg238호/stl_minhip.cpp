/*
	STL_MINHIP
	priority_queue�� min heap���� ����� �� �ְԵȴ�.
	max heap�� ��쿡�� ����������ϴ� �͵� �ִ�.

*/

#include <iostream> 
#include <functional> 
#include <queue> 
using namespace std;

class St {
public:
	St(int x, int y) : _x(x), _y(y) {}

	void print() { cout << "rect : " << _x << " * " << _y << " = " << _x * _y << endl; }

	// greater-than operator > �� �����մϴ�. �� operator�� min-heap�� ������ �� ���Դϴ�. 
	// class ��ſ� struct�� ���� �͵� �����մϴ�. 
	bool operator > (const St& rhs) const { return _x*_y  > rhs._x * rhs._y; }

private:
	int _x, _y;
};

int main()
{
	// min-heap�� �����մϴ�. 
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