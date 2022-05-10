#include <iostream>
#include <string.h>
using namespace std;

void test1() {

	int *p = (int *)malloc(4);
	*p = 10;

	cout << p << endl;
	cout << &p << endl;
	cout << *p << endl;

	free(p);
}

void test2() {
	int *p = new int;
	*p = 0xaaaaaaaa;

	cout << p << endl;
	cout << &p << endl;
	cout << *p << endl;

	delete p;
}

void test3() {
	int *p = new int[4];
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;

	cout << p << endl;
	cout << &p << endl;
	cout << *p << endl;

	delete[] p;
}

void test4() {
	int *p0 = new int;
	int *p1 = new int();
	int *p2 = new int(3);

	//cout << *p0 << endl;
	//cout << *p1 << endl;
	//cout << *p2 << endl;
}

int main() {
	int *p0 = (int *)malloc(4);
	memset(p0, 1, 4);

	cout << p0 << endl;
	cout << &p0 << endl;
	cout << *p0 << endl;

	return 0;
}