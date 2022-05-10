//
//  main.cpp
//  cpp_test
//
//  Created by Yu Yang on 2022/3/22.
//

#include <iostream>
using namespace std;

// display_v
void display() {
    cout << "display()" << endl;
}

// display_i
void display(int a) {
    cout << "display(int) - " << a << endl;
}

// display_l
void display(long a) {
    cout << "display(long) - " << a << endl;
}

// display_d
void display(double a) {
    cout << "display(double) - " << a << endl;
}


int sum(int v1 = 3, int v2 = 4) {
    return v1 + v2;
}

void test() {
    sum(1);
    sum(1, 2);
}

void test1() {
    int a = 10;
    int a1 = 10;
    int b = a++ + a++;
    int c = ++a1 + ++a1;
    cout << a << endl;
    cout << b << endl;
    cout << endl;
    cout << a1 << endl;
    cout << c << endl;
}

void test2() {
    display();
    display(10);
    display(10L);
    display(10.0);
}

void test3() {
    int a = 10;
    int b = 20;
    int *p = &a;
    *p += 30;
    p = &b;
    *p += 30;
    cout << a << endl;
    cout << b << endl;
}

void test4() {
    int a = 10;
    int b = 20;
    int &p = a;
    p += 30;
//    &p = b;
    p += 30;
    cout << a << endl;
    cout << b << endl;
}


void swapInt1(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapInt2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapInt3(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main1(int argc, const char * argv[]) {

    int a = 10;
    int b = 20;
//    swapInt1(a, b);
//    swapInt2(&a, &b);
    swapInt3(a, b);
    
    cout << "a=" << a << ", b=" << b << endl;
 
    return 0;
}


// ----------------------------------------------面向对象----------------------------------------------
// ----------------------------------------------面向对象----------------------------------------------
// ----------------------------------------------面向对象----------------------------------------------
// ----------------------------------------------面向对象----------------------------------------------
// ----------------------------------------------面向对象----------------------------------------------


struct Person {
    int m_id;
    int m_age;
    int m_height;
    
    void run() {
        
    }
};

int main2(int argc, const char * argv[]) {

    Person person;
    person.m_id = 1;
    person.m_age = 2;
    person.m_height = 3;
    
    cout << "&person " << &person << endl;
    cout << "&m_id " << &person.m_id << endl;
    cout << "&m_age " << &person.m_age << endl;
    cout << "&m_height " << &person.m_height << endl;

    return 0;
}

int main3(int argc, const char * argv[]) {

    Person person;
    person.m_id = 1;
    person.m_age = 2;
    person.m_height = 3;
    
    cout << "&person " << &person << endl;
    cout << "&m_id " << &person.m_id << endl;
    cout << "&m_age " << &person.m_age << endl;
    cout << "&m_height " << &person.m_height << endl;

    
    return 0;
}


// ----------------------------------------------拷贝函数----------------------------------------------
// ----------------------------------------------拷贝函数----------------------------------------------
// ----------------------------------------------拷贝函数----------------------------------------------
// ----------------------------------------------拷贝函数----------------------------------------------


class Car {
    int m_price;
    int m_length;
    char *m_name;
public:
    Car(int price = 0, int length = 0, char *name = NULL) : m_price(price), m_length(length), m_name(name) {
        cout << "Car(int price = 0, int length = 0)" << endl;
    }

//    // 拷贝构造函数
//    Car(const Car &car) {
//        cout << "Car(const Car &car)" << endl;
//        m_price = car.m_price;
//        m_length = car.m_length;
//    }
    
    void display() {
        cout << m_price << ", " << m_length << endl;
    }
};

int main4(int argc, const char * argv[]) {

    char name[] = {'a', 'b', 'c', '\0'};
    Car car1(3, 4, name);
    Car car2(car1);
    
    cout << name << endl;
    cout << &name << endl;

    cout << &car1 << endl;
    cout << &car2 << endl;

    
    return 0;
    
}



int main(int argc, const char * argv[]) {


    
    return 0;
    
}
