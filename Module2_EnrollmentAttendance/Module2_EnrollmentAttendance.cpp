#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    string rollNo;

public:
    Student(string n, string r) {
        name = n;
        rollNo = r;
    }

    string getName() const { return name; }
    string getRollNo() const { return rollNo; }

    void display() const {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};

class Section {
private:
    string courseName;
    string sectionName;
    int capacity;
    vector<Student> students;

public:
    Section(string course, string section, int cap) {
        courseName = course;
        sectionName = section;
        capacity = cap;
    }

    void displayInfo() const {
        cout << courseName << " | Section: " << sectionName
             << " | Capacity: " << capacity << endl;
    }
};

int main() {
    Student s1("Muhammad Sohaib", "F202533201");
    Student s2("Namra Imran", "F202533202");
    Student s3("Maham Mohsin", "F202533203");
    Student s4("Rabiya Imtiaz", "F202533204");
    Student s5("Nawaira Mushtaq", "F202533205");
    Student s6("Hamza Rahim", "F202533206");
    Student s7("Taha", "F202533207");

    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    s6.display();
    s7.display();

    Section sec("Object Oriented Programming", "D1", 5);
    sec.displayInfo();

    return 0;
}
