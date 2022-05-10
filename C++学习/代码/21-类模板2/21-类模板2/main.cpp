#include <iostream>
using namespace std;

template <typename Element>
class Array {
	friend ostream &operator<<<>(ostream &cout, const Array<Element> &array);
	Element *m_datas;
	int m_capacity;
	int m_size;

public:
	Array(int capacity) {
		m_capacity = (capacity > 0) ? capacity : 10;
		m_datas = new Element[capacity];
	}

	~Array() {
		delete[] m_datas;
	}

	int size() {
		return m_size;
	}

	void add(Element value) {
		if (m_size >= m_capacity) { return; }
		m_datas[m_size++] = value;
	}

	Element get(int index) {
		if (index >= m_size) { throw "out of bounds"; }
		//if (index >= m_size) { return 0; }
		return m_datas[index];
	}

	Element operator[](int index) {
		return get(index);
	}
};

template <typename Element>
ostream &operator<<<>(ostream &cout, const Array<Element> &array) {
	cout << "[";
	
	for (size_t i = 0; i < array.m_size; i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << array.m_datas[i];
	}
	return cout << "]";
}

int main() {

	Array<float> array(5);
	array.add(10);
	array.add(20);
	array.add(30);
	array.add(40);
	array.add(50);

	/*
	cout << array.size() << endl;
	cout << array.get(0) << endl;
	cout << array.get(1) << endl;
	cout << array.get(2) << endl;
	cout << array.get(3) << endl;
	cout << array.get(4) << endl;
	

	cout << array[0] << endl;
	cout << array[1] << endl;
	cout << array[2] << endl;
	cout << array[3] << endl;
	cout << array[4] << endl;
	*/

	cout << array << endl;

	return 0;
}