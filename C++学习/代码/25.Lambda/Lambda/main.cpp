#include <iostream>
using namespace std;

/*
int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}
*/

int exec(int v1, int v2, int (*func)(int, int)) {
	return func(v1, v2);
}

int main() {

	/*
	int (*add)(int ,int) = [](int a, int b) -> int {
		return a + b;
	};

	add(11, 21);
	*/

	// cout << add(11, 21) << endl;
	
	/*
	cout << exec(10, 20, add) << endl;
	cout << exec(10, 20, sub) << endl;
	cout << exec(10, 20, multiply) << endl;
	cout << exec(10, 20, divide) << endl;
	*/

	// exec(10, 20, [](int v1, int v2) {return v1 + v2; });

	cout << exec(10, 20, [](int v1, int v2) {return v1 + v2; }) << endl;
	cout << exec(10, 20, [](int v1, int v2) {return v1 - v2; }) << endl;
	cout << exec(10, 20, [](int v1, int v2) {return v1 * v2; }) << endl;
	cout << exec(10, 20, [](int v1, int v2) {return v1 / v2; }) << endl;

	//getchar();
	return 0;
}