#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
class Student{
    std::string Name, RollNo;
    float CGPA;
    public:
        Student();
        Student(std::string Name, std::string RollNo,float CGPA);
        ~Student();
        void addStudent();
        void search();
        void update();
        
};

#endif // STUDENT_H
