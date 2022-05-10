#include <iostream>
using namespace std;

class Person {
public:
	int age;
	int height;

	Person() { //: Person(10, 20)
		Person(10, 20);
	}

	Person(int a, int h) {
		age = a;
		height = h;
	}
};

int main() {

	Person p;
	cout << p.age << endl;
	cout << p.height << endl;

	return 0;
}