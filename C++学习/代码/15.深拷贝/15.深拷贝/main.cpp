#include <iostream>
using namespace std;

class Car {
public:
	int m_price;
	char *m_name;

	Car(int price = 0, const char *name = NULL) : m_price(price) {
		if (name == NULL) { return; }

		m_name = new char[strlen(name) + 1]();
		strcpy(m_name, name);
	}

	
	~Car() {
		if (m_name == NULL) { return; }
		delete[] m_name;
	}
	

	void display() {
		cout << m_price << " " << m_name << endl;
	}
};

int main() {

	Car car1(10, "abc");
	Car car2(car1);

	car1.display();
	car2.display();


	return 0;
}