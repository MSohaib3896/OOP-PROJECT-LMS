#include <iostream>
#include <string>
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

    string getName() { return name; }
    string getRollNo() { return rollNo; }

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};

int main() {
    Student s1("Muhammad Sohaib", "F202533201");
    Student s2("Namra Imran", "F202533202");
    Student s3("Maham Mohsin", "F202533203");
    Student s4("Rabiya Imtiyaz", "F202533204");
    Student s5("Nawaira Mushtak","F202533205");

    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
    return 0;
}
