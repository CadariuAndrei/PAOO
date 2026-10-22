#include "Student.h"
#include <utility>

int main() {
    cout << "Constructor" << endl;
    int initialGrades[] = {8, 9, 10};
    Student s1("James", 3, initialGrades);
    s1.print();

    cout << "Copy Constructor" << endl;
    Student s2 = s1;
    s2.modifyGrade(0, 4); 
    
    s1.print();
    s2.print();

    cout << "\nMove Constructor" << endl;
    Student s3 = move(s1);
    
    s3.print();
    s1.print();

    cout << "\n Destructors" << endl;
    return 0;
}