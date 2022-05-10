#include <iostream>
using namespace std;

class Person {
public:
	void run() {
		cout << "Person::run()" << endl;
	}

	Person() {
		cout << "Person::Person()" << endl;
	}

	virtual ~Person() {
		cout << "~Person::Person()" << endl;
	}
};


class Student: Person {
public:
	Student() {
		cout << "Student::Student()" << endl;
	}

	~Student() {
		cout << "~Student::Student()" << endl;
	}
};

int main() {
	Person *p = (Person *)new Student;
	p->run();
	delete p;

	return 0;
}