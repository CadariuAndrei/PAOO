#include "Student.h"

Student::Student(string name, int numberOfGrades, const int* grades) 
    : name(name), numberOfGrades(numberOfGrades), grades(new int[numberOfGrades]) {
    for (int i = 0; i < this->numberOfGrades; i++) {
        this->grades[i] = grades[i];
    }
    cout << "Constructor " << this->name << " array adress : " << this->grades << "" << endl;
}

Student::~Student() {
    if (this->grades != nullptr) {
        cout << "Destructor " << this->name << " array adress : " << this->grades << "" << endl;
        delete[] this->grades;
    } else {
        cout << "Destructor " << this->name << " nullptr" << endl;
    }
}


Student::Student(const Student& other) 
    : name(other.name + " (Copie)"), numberOfGrades(other.numberOfGrades), grades(new int[other.numberOfGrades]) {
    for (int i = 0; i < this->numberOfGrades; i++) {
        this->grades[i] = other.grades[i];
    }
    cout << "Copy Constructor " << this->name << " array adress : " << this->grades << "" << endl;
}

Student::Student(Student&& other) noexcept 
    : name(other.name + " (Mutat)"), numberOfGrades(other.numberOfGrades), grades(other.grades) {
    other.grades = nullptr;
    other.numberOfGrades = 0;
    cout << "Move Constructor " << this->name << " array adress : " << this->grades << "" << endl;
}

void Student::modifyGrade(int index, int newGrade) {
    if (this->grades != nullptr && index >= 0 && index < this->numberOfGrades) {
        this->grades[index] = newGrade;
    }
}

void Student::print() const {
    cout << "Student: " << this->name << " | Grades: ";
    if (this->grades != nullptr) {
        for (int i = 0; i < this->numberOfGrades; i++) {
            cout << this->grades[i] << " ";
        }
        cout << "array adress : " << this->grades << "" << endl;
    } else {
        cout << "nullptr" << endl;
    }
}