#include <iostream>
#include "student.h"
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class Student{
private:
string Name, RollNo;
float CGPA;

public:
Student():Name(""), RollNo(""),CGPA(0.0){}

void setName(string name){
	Name = name;
}

void setRollNo(string rollNo) { 
 RollNo = rollNo;
}

void setCGPA(float cgpa) { 
 CGPA = cgpa;
}

string getName(){
	return Name;
}


string getRollNo() {
 return RollNo;
}

float getCGPA() {
 return CGPA;
}

};
