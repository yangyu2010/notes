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

int main(int argc, const char * argv[]) {

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
