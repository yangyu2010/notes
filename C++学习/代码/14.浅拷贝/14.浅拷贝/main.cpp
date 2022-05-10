#include <iostream>
using namespace std;

class Car {
public:
	int m_price;
	char *m_name;
	
	Car(int price = 0, const char *name = NULL): m_price(price) {
		if (name == NULL) { return; }

		m_name = new char[strlen(name) + 1]();
		strcpy(m_name, name);
	}

	/*
	~Car() {
		if (m_name == NULL) { return; }
		delete[] m_name;
	}
	*/

	void display() {
		cout << m_price << " " << m_name << endl;
	}
};

int main() {

	/*
	char name[] = {'a', 'b', 'c', '\0'};
	Car car(100, name);
	car.display();
	*/

	//char name[] = { 't', 'b', 'c', '\0' };
	//cout << *name << endl;

	const char *ch1 = "jili";
	//char a = *ch1;

	cout << *ch1 << endl;
	//printf("%c", *ch1);

	
	Car car(10, "benz");
	//Car car2(car);

	//cout << sizeof(Car) << endl;
	cout << &car << endl;
	//cout << &car2 << endl;


	//car2.display();
	//*car.m_name = 'a';

	cout << &car.m_price << endl;
	cout << &car.m_name << endl;
	cout << *car.m_name << endl;

	return 0;
}