#include <iostream>
using namespace std;

struct Student {
	int m_age;
	void run() {
		cout << "Student::run()" << endl;
	}
};

struct Worker {
	int m_age;
	void run() {
		cout << "Worker::run()" << endl;
	}
};

struct Undergraduate : Student, Worker {
	int m_age;
	void run() {
		cout << "Undergraduate::run()" << endl;
	}
};

int main() {
	Undergraduate ug;
	ug.run();
	ug.Student::run();
	ug.Worker::run();
	ug.Undergraduate::run();

	cout << &ug << endl;

	ug.m_age = 1;
	ug.Student::m_age = 2;
	ug.Worker::m_age = 3;
	ug.Undergraduate::m_age = 4;

	return 0;
}