#pragma once

#include <iostream>

using namespace std;

class Student {
private:
	int ID;
	string name;
	string phone;

public:
	Student():ID(0),name(""),phone(""){}
	Student(int id,string n,string p):ID(id),name(n),phone(p){}
	~Student(){}

	int getId() {
		return ID;
	}

	string getName() {
		return name;
	}

	string getPhone() {
		return phone;
	}

	void setId(int id) {
		ID = id;
	}

	void setName(string name) {
		this->name = name;
	}

	void setPhone(string phone) {
		this->phone = phone;
	}

	void toString() {
		cout << "ID=" << ID << ",name=" << name << ",phone=" << phone << endl;
	}

};
