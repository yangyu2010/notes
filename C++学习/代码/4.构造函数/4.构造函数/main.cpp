#include <iostream>
#include <string.h>
using namespace std;


class Person {
public:
	int id;
	int age;
	int height;

	Person() {
		id = 0;
		age = 0;
		height = 0;

		cout << "Person::Person()" << endl;
	}

	Person(int id, int age, int height) {
		this->id = id;
		this->age = age;
		this->height = height;

		cout << "Person::Person(id:age:height)" << endl;
	}

	/*
	Person(int m_id, int m_age, int m_height) {
		id = m_id;
		age = m_age;
		height = m_height;
	}*/

};

int main1() {

	Person person(10, 20, 30);
	//person.id = 1;
	//person.age = 2;
	//person.height = 3;

	//cout << "&person " << &person << endl;

	int *p = (int *)&person;
	cout << "*p " << *p << endl;

	cout << "id is " << person.id << endl;
	cout << "age is " << person.age << endl;
	cout << "height is " << person.height << endl;

	return 0;
}


int main() {

	Person *p1 = new Person;
	Person *p2 = new Person();
	Person *p3 = new Person(11, 12, 13);

	Person p4;
	Person p5();
	Person p6(21, 22, 23);

	// 函数的声明, 不是初始化一个person
	// 类似这样
	// int sum();
	// Person p5();

	delete p1;
	delete p2;
	delete p3;


	return 0;
}