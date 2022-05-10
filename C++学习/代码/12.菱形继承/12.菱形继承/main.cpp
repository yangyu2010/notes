#include <iostream>
using namespace std;

struct Person {
	int m_age;
};

struct Student: Person {
	int m_score;
};

struct Worker : Person {
	int m_salary;
};

struct Undergraduate : Student, Worker {
	int m_grade;
};


int main() {

	Undergraduate ug;

	cout << sizeof(ug) << endl;
	cout << &ug << endl;

	ug.m_score = 1;
	ug.m_salary = 2;
	ug.m_grade = 3;
	ug.Student::m_age = 4;
	ug.Worker::m_age = 5;

	//cout << sizeof(ug) << endl;

	return 0;
}