#include <iostream>
using namespace std;

class Person {
	int age;
public:
	
	Person(int a) : age(a) {}
};

class Student : Person {
	int score;
public:
	Student() : Person(10) {
		score = 0;
	}

	Student(int a, int s) : score(s), Person(a) {

	}
};

int main() {

	Student stu;

	return 0;
}