#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {

private:
    string name;
    int numberOfGrades;
    int* grades; 

public:
    Student(string nume, int numberOfGrades, const int* grades);

    ~Student();

    Student(const Student& other);

    Student(Student&& other) noexcept;

    void modifyGrade(int index, int newGrade);
    void print() const;
};