#include <iostream>
using namespace std;


int main() {

	/*
	int a = 10;
	auto func = [&a] {
		a++;
		cout << a << endl;
	};
	func();
	cout << a << endl;
	*/

	int a = 10;
	auto func = [a]() mutable {
		a++;
		cout << a << endl;
	};
	func();
	cout << a << endl;

	return 0;
}


int main1() {

	int a = 10;
	int b = 20;

	/*
	void (*func)() = [a, b] {
		cout << a << endl;
		cout << b << endl;
	};
	*/


	auto func = [&a, &b] {
		cout << a << endl;
		cout << b << endl;
	};

	/*
	void (*func2)() = [a, b] {
		cout << "*func2" << endl;
	};
	*/

	 //decltype(func);
	decltype(func);

	a = 30;
	b = 40;

	func();
	// func2();

	//getchar();
	return 0;
}