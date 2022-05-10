#include <iostream>
using namespace std;


struct Animal {
	int age;
	int height;

	virtual void speak() {
		cout << "Animal::speak()" << endl;
	}
	
	virtual void run() {
		cout << "Animal::run()" << endl;
	}
};

struct Dog : Animal {
	// 重写（覆写、覆盖、override）
	void speak() {
		cout << "Dog::speak()" << endl;
	}
	void run() {
		cout << "Dog::run()" << endl;
	}
};

struct Cat : Animal {
	void speak() {
		cout << "Cat::speak()" << endl;
	}
	void run() {
		cout << "Cat::run()" << endl;
	}
};

struct Pig : Animal {
	void speak() {
		cout << "Pig::speak()" << endl;
	}
	void run() {
		cout << "Pig::run()" << endl;
	}
};

void liu(Animal *p) {
	p->speak();
	p->run();
}

int main() {
	
	Animal *ani = new Cat();
	//cout << ani << endl;
	//cout << &ani << endl;

	ani->run();
	ani->speak();

	return 0;
}