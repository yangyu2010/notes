#include <iostream>
using namespace std;

class Person {
	int m_age;
public:
	Person() {
		cout << "Person()" << endl;
	}
	Person(int age): m_age(age) {
		cout << "Person()" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
	void run() {
		cout << "run() " << m_age << endl;
	}
};

void test() {
	//Person p(20);
	//p.run();

	//Person *p = new Person(10);
	//p->run();

	auto_ptr<Person> p(new Person(10));
	p->run();

};

int main() {

	test();

	getchar();
	return 0;
}