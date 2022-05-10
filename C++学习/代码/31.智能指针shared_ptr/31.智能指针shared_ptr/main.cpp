#include <iostream>
using namespace std;

class Car;
class Person {
public:
	shared_ptr<Car> m_car = nullptr;
	Person() {
		cout << "Person()" << endl;
	}

	~Person() {
		cout << "~Person()" << endl;
	}
};

class Car {
public:
	//shared_ptr<Person> m_person = nullptr;
	weak_ptr<Person> m_person;
	Car() {
		cout << "Car()" << endl;
	}

	~Car() {
		cout << "~Car()" << endl;
	}
};


int main() {

	//test();

	//shared_ptr<Person []> p(new Person[10]);
	//p->run();


	shared_ptr<Person> p1(new Person);
	shared_ptr<Car> p2(new Car);
	p1->m_car = p2;
	p2->m_person = p1;

	//getchar();
	return 0;
}