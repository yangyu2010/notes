#include <iostream>
using namespace std;

/*
int add(int a, int b) {
	return a + b;
}

int add(double a, double b) {
	return a + b;
}
*/

/*
template <class T> T add(T a, T b) {
	return a + b;
}
*/
template <typename T> T add(T a, T b) {
	return a + b;
}


int main() {
	int a = add<int>(1, 2);
	double b = add<double>(1.5, 2.6);
	cout << a << endl;
	cout << b << endl;

	return 0;
}