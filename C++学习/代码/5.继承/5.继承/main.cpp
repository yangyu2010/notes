#include <iostream>
#include <string.h>
using namespace std;


class Person {
	int age = 10;
	int height = 9;
};

class Student : Person {
	int score = 11;

	void study() {
		//age = 10;
	}
};


int main() {

	Student stu;
	cout << &stu << endl;
	cout << &stu << endl;

	int *s = (int *)&stu;

	cout << *(s+1) << endl;

	return 0;
}