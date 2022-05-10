#include <iostream>
using namespace std;


int divide(int v1, int v2) {
	if (v2 == 0) {
		throw 999;
	}
	return v1 / v2;
}

int main() {

	int a = 10;
	int b = 0;

	cout << 1 << endl;

	try {
		int c = divide(a, b);
		cout << c << endl;
	} catch (int exception) {
		cout << "产品了异常: " << exception << endl;
	}

	cout << 2 << endl;

	return 0;
};

int main1() {

	cout << 1 << endl;

	/*
	for (int i = 0; i < 99999999; i++)
	{
		int *p = new int[99999];
	}
	*/

	for (int i = 0; i < 99999999; i++)
	{
		try {
			int *p = new int[99999999];
			cout << 2 << endl;
		} catch (...) {
			cout << "产品了异常" << endl;
			break;
		}
	}

	cout << 3 << endl;

	//getchar();
	return 0;
}