#pragma once

#include <iostream>
using namespace std;

template <typename Element>
class Array {
	friend ostream &operator<<<>(ostream &cout, const Array<Element> &array);
	Element *m_datas;
	int m_capacity;
	int m_size;

public:
	Array(int capacity);
	~Array();
	int size();
	void add(Element value);
	Element get(int index);
	Element operator[](int index);
};

template <typename Element>
Array<Element>::Array(int capacity) {
	m_capacity = (capacity > 0) ? capacity : 10;
	m_datas = new Element[capacity];
}

template <typename Element>
Array<Element>::~Array() {
	delete[] m_datas;
}

template <typename Element>
int Array<Element>:: size() {
	return m_size;
}

template <typename Element>
void Array<Element>:: add(Element value) {
	if (m_size >= m_capacity) { return; }
	m_datas[m_size++] = value;
}

template <typename Element>
Element Array<Element>:: get(int index) {
	if (index >= m_size) { throw "out of bounds"; }
	//if (index >= m_size) { return 0; }
	return m_datas[index];
}

template <typename Element>
Element Array<Element>:: operator[](int index) {
	return get(index);
}

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

