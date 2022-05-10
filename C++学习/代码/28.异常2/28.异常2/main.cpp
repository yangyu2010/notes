#include <iostream>
using namespace std;

class Exception {
public:
	virtual const char * desc() const = 0;
	virtual int code() const = 0;
};

class DivideException : public Exception {
public:
	const char * desc() const  {
		return "不能除以0";
	};

	int code() const  {
		return 400;
	}
};

class AddException : public Exception {
public:
	const char * desc() const {
		return "加法有问题";
	};

	int code() const {
		return 403;
	}
};

int divide(int v1, int v2) {
	if (v2 == 0) {
		throw DivideException();
	}
	return v1 / v2;
}

int main() {


	int a = 10;
	int b = 0;

	cout << 1 << endl;

	try {
		int c = divide(a, b);
		cout << c << endl;
	}
	catch (int exception) {
		cout << "产品了异常: " << exception << endl;
	}
	catch (const Exception &exception) {
		cout << "产品了异常: " << exception.desc() << endl;
	}

	cout << 2 << endl;


	//getchar();
	return 0;
}

/*
class Exception {
public:
	virtual const char * desc() = 0;
};

class DivideException: public Exception {
public:
	const char * desc() {
		return "不能除以0";
	};
};

int divide(int v1, int v2) {
	if (v2 == 0) {
		throw DivideException();
	}
	return v1 / v2;
}

int main() {


	int a = 10;
	int b = 0;

	cout << 1 << endl;

	try {
		int c = divide(a, b);
		cout << c << endl;
	} catch (int exception) {
		cout << "产品了异常: " << exception << endl;
	} catch (DivideException exception) {
		cout << "产品了异常: " << exception.desc() << endl;
	}

	cout << 2 << endl;


	//getchar();
	return 0;
} 
*/