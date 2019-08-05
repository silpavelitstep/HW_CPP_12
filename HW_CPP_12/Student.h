#ifndef STUDENT_H
#define STUDENT_H
class Student {
	char* name;
	int birthYear;
	int group;
	int salary;
public:
	void goLection();
	void goExem();
	void goHome();
};
class Aspirant :public Student {
public:
	void editSciWork();
	void defendSciWork();
};
#endif // !STUDENT_H