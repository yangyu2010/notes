#include <iostream>
using namespace std;

class Array {
	int *m_datas;
	int m_capacity;
	int m_size;

public:
	Array(int capacity) {
		m_capacity = (capacity > 0) ? capacity : 10;
		m_datas = new int[capacity];
	}

	~Array() {
		delete[] m_datas;
	}

	int size() {
		return m_size;
	}

	void add(int value) {
		if (m_size >= m_capacity){ return; }
		m_datas[m_size++] = value;
	}

	int get(int index) {
		//if (index >= m_size) { throw "out of bounds"; }
		if (index >= m_size) { return 0; }
		return m_datas[index];
	}
};

int main() {

	Array array(1);
	array.add(10);
	array.add(20);
	array.add(30);
	array.add(40);
	array.add(50);


	cout << array.size() << endl;
	cout << array.get(0) << endl;
	cout << array.get(1) << endl;
	cout << array.get(2) << endl;
	cout << array.get(3) << endl;
	cout << array.get(4) << endl;


	return 0;
}