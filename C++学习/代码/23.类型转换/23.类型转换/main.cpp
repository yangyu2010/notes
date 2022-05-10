#include <iostream>
using namespace std;

class Person {
	virtual void run() {
	}
};

class Car {

};

int main() {
	// 0a 00 00 00
	int a = 10;

	// 00 00 00 00 00 00 24 40
	double b = a;
	
	// 内存拷贝
	// 0a 00 00 00 cc cc cc cc
	double c = reinterpret_cast<double &>(a);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	return 0;
}


int main4() {
	int a = 10;
	double b = a;
	double c = (double)a;
	double d = double(a);
	double e = static_cast<double>(a);
	//double f = const_cast<double>(a);

	Person *p1 = new Person();
	const Person *p2 = p1;
	const Person *p3 = static_cast<const Person *>(p1);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;

	return 0;
}

int main3() {
	Person *p1 = new Person();
	//Car *car1 = (Car *)p1;
	Car *car2 = dynamic_cast<Car *>(p1);

	/*
	cout << p1 << endl;
	cout << car1 << endl;
	cout << car2 << endl;
	*/


	/*
	Car *car1 = (Car *)p1;
	00C25641  mov         eax,dword ptr [p1]  
	00C25644  mov         dword ptr [car1],eax 
	*/

	/*
	009F5641  push        0
	009F5643  push        offset Car `RTTI Type Descriptor' (09FA1E8h)
	009F5648  push        offset Person `RTTI Type Descriptor' (09FA1D0h)
	009F564D  push        0
	009F564F  mov         eax,dword ptr [p1]
	009F5652  push        eax
	009F5653  call        ___RTDynamicCast (09F1451h)
	009F5658  add         esp,14h
	009F565B  mov         dword ptr [car2],eax
	*/

	return 0;
}


int main2() {
	const Person *p1 = new Person();
	Person *p2 = (Person *)p1;
	Person *p3 = const_cast<Person *>(p1);

	/*
	01341BD2  mov         eax,dword ptr [p1]  
	01341BD5  mov         dword ptr [p2],eax  
	*/
	/*
	013F1BD2  mov         eax,dword ptr [p1]  
	013F1BD5  mov         dword ptr [p3],eax 
	*/


	return 0;
}

int main1() {
	int a = 10;
	double b = a;
	double c = (double)a;
	double d = double(a);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	return 0;
}