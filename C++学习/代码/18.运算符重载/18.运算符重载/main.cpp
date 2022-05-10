#include <iostream>
using namespace std;

class Point {
	//friend Point add(Point, Point);
	//friend Point operator+(Point, Point);
	//friend bool operator==(Point, Point);

	int m_x;
	int m_y;
public:
	int getX() { return m_x; };
	int getY() { return m_y; };
	Point(int x, int y) : m_x(x), m_y(y) {};
	void display() {
		cout << m_x << " " << m_y << endl;
	}

	/*
	前面的const确保返回值是const类型 不能被赋值
	保证不被这样
	(p1+p2) = Point(1, 2)
	类似不能(1+2) = 3

	后面的const是表示函数是const函数
	为了保证 返回值是const时也能调用函数
	p1 + p2 + p3
	*/
	const Point operator+(const Point &p) const  {
		return Point(m_x + p.m_x, m_y + p.m_y);
	}

	Point &operator+=(const Point &p) {
		m_x += p.m_x;
		m_y += p.m_y;
		return *this;
	}
};

/*
Point add(Point p1, Point p2) {
	//return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
	return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}

Point operator+(Point p1, Point p2) {
	return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}

bool operator==(Point p1, Point p2) {
	return p1.m_x == p2.m_x && p1.m_y == p2.m_y;
}
*/


int main() {
	/*
	Point p1(30, 20);
	Point p2(30, 40);
	Point p3 = p1 + p2;
	p3.display();
	*/
	Point p1(30, 20);
	Point p2(40, 40);
	Point p3(50, 50);
	//p1 + p2 + p3;

	/*
	p1 += p2;
	p1.display();
	p2.display();
	*/

	(p1 += p2) = Point(1, 2);
	p1.display();
	p2.display();


	/*
	int a = 1;
	int b = 2;
	(a += b) = 10;
	cout << a << endl;
	cout << b << endl;
	*/

	//Point p3 = add(p1, p2);
	//Point p3 = p1 + p2;
	//Point p3 = operator+(p1, p2);

	//bool bl = p1 == p2;
	//cout << bl << endl;

	return 0;
}