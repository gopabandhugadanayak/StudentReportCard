#include<iostream>
#include<string>
#include "student.cpp"
#include "student.h"



void addStudent(Student s){
string name, rollNo;
float cgpa;

cout<<"Enter Name Of Student: ";
cin>>name;
s.setName(name);

cout << "Enter RollNo of Student: ";
cin >> rollNo;
s.setRollNo(rollNo);

cout << "Enter CGPA of Student: ";
cin >> cgpa;
s.setCGPA(cgpa);

ofstream out("D:/Student.txt", ios::app);
if(!out){
	cout<<"ERROR: File Not Opened!"<<endl;
}
else{
out<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getCGPA()<<endl;
cout<<"Student Added Successfuly!"<<endl;
}
out.close();
}

void search(Student s){
string name;
cout<<"Enter Name of Student: ";
cin>>name;

ifstream in("D:/Student.txt");
if(!in){
cout<<"Error: File Can Not Open!"<<endl;
}
else{
string line;
bool found = false;
while(getline(in,line)){
int pos = line.find(name);
if(pos != string::npos){
 cout << " Name | RollNo | CGPA" << endl;
 cout << line << endl;
 found = true;
}
}
if(!found){
	cout<<"Student Not Found!"<<endl;
}
}
}

void update(){
	string rollNo;
cout<<"Enter RollNo of Student: ";
cin>>rollNo;

ifstream in("D:/Student.txt");
if(!in){
	cout<<"Error:"<<endl;
}
ofstream out("D:/Student Temp.txt");
if(!out){
	cout<<"Error:";
out.close();
}
string line;
bool found = false;
while(getline(in,line)){
 int pos = line.find(rollNo);
 if (pos != string::npos) {
  found = true;
  
  float newcgpa;
  cout<<"Enter New CGPA: ";
  cin>>newcgpa;
  
  stringstream ss;
  ss<<newcgpa;
  string newCGPA = ss.str();
  
  int cgpaPos = line.find_last_of(':');
  line.replace(cgpaPos+2, string::npos, newCGPA);
  cout<<"CGPA updated for: "<<rollNo<<endl;
}
out<<line<<endl;
}
if(!found){
	cout<<"Student Not found!"<<endl;
}
out.close();
in.close();
remove("D:/Student.txt");
rename("D:/Student Temp.txt", "D:/Student.txt");
}



int main(){
Student s;
bool exit = false;
while(!exit){
system("cls");
std::cout << "Welcome To Student Management System" << endl;
std::cout << "************************************" << endl;
std::cout << "1.Add Student." << endl;
std::cout << "2.Search Student." << endl;
std::cout << "3.Update Student." << endl;
std::cout << "4.Exit" <<endl;
std::cout << "Enter Choice: ";
int val;
cin >> val;

if(val==1){
system("cls");
addStudent(s);
Sleep(4000);
}

else if(val==2){
system("cls");
search(s);
Sleep(5000);	
}

else if(val==3){
system("cls");
update();
Sleep(5000);	
}

else if(val==4){
	system("cls");
	exit = true;
	cout<<"Good Luck!";
	Sleep(3000);
}
}
}