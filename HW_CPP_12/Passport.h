#pragma once
#ifndef PASSPORT_H
#define PASSPORT_H
class Passport {
protected:
	char* name;
	char* surname;
	struct Date {
		char day;
		char month;
		short year;
	};
	Date birthDay;
	Date issueDate;
	char* issuePlace;
	char sex;
	int number;//need 9 numerals
	
public:
	void showForControl();
	void change();

};
class ForeignPassport :public Passport {
	char fullNumber[150];
	struct Visa {
		Date since;
		Date until;
		Date issueDate;
		char* issuePlace;
		char* country;
	};
	Visa* listVisas;//listVisa=new Visa[20]

};
#endif // !PASSPORT_H