#include <iostream>
#include <string.h>
using namespace std;


class Person {
public:
	int id;
	int age;
	int height;

	void run() {
		id = 10;
		age = 20;
		height = 30;
		//cout << "id = " << id << endl;
		//cout << "age = " << age << endl;
		//cout << "height = " << height << endl;
	}
};

int main() {

	Person person;
	person.id = 1;
	person.age = 2;
	person.height = 3;
	person.run();

	return 0;
}