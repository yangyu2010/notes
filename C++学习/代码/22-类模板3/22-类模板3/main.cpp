#include <iostream>
#include "Array.hpp"

using namespace std;


int main() {

	Array<float> array(3);
	array.add(10);
	array.add(20);
	array.add(30);
	array.add(40);
	array.add(50);

	cout << array.size() << endl;


	/*
	cout << array.get(0) << endl;
	cout << array.get(1) << endl;
	cout << array.get(2) << endl;
	cout << array.get(3) << endl;
	cout << array.get(4) << endl;
	*/

	cout << array[0] << endl;
	cout << array[1] << endl;
	cout << array[2] << endl;
	cout << array[3] << endl;
	cout << array[4] << endl;
	

	// cout << array << endl;

	return 0;
}