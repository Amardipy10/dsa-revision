#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    double cgpa;

    // Constructor
    Student(string name, double cgpa) {
        this->name = name;
        this->cgpa = cgpa;
    }

    // Member function
    void getInfo() {
        cout << "name : " << name << endl;
        cout << "cgpa : " << cgpa << endl;
    }
};

int main() {
    Student s1("Atul", 8.5);
    s1.getInfo();

    return 0;
}