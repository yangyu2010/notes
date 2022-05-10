#include <iostream>
using namespace std;

struct Student {
	int m_class;
	int m_score;
	//Student(int score) :m_score(score) {}
	virtual void study() {
		cout << "Student::study() - score = " << m_score << endl;
	}
};

struct Worker {
	int m_salary;
	//Worker(int salary) :m_salary(salary) {}
	virtual void work() {
		cout << "Worker::work() - salary = " << m_salary << endl;
	}
};

struct Undergraduate : Student, Worker {
	int m_grade;
	//Undergraduate(int score, int salary, int grade)
		//:m_grade(grade),
		//Student(score),
		//Worker(salary) {}
	void play() {
		cout << "Undergraduate::play() - grade = " << m_grade << endl;
	}

	void study() {
		cout << "Undergraduate::study() - score = " << m_score << endl;
	}

	void work() {
		cout << "Undergraduate::work() - salary = " << m_salary << endl;
	}
};
int main() {

	/*
	Undergraduate ug;
	ug.m_score = 100;
	ug.m_salary = 2000;
	ug.m_grade = 4;
	ug.study();
	ug.work();
	ug.play();
	*/

	/*
	Undergraduate ug;
	ug.m_grade = 1;
	ug.m_salary = 2;
	ug.m_score = 3;
	ug.m_class = 4;
	ug.study();
	ug.work();
	cout << &ug << endl;
	cout << sizeof(ug) << endl;
	*/

	Student *stu = new Undergraduate;
	stu->m_class = 1;
	stu->m_score = 2;
	stu->study();

	return 0;
}