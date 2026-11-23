#include <string>
#include <iostream>
using namespace std;
class Course {
private:
    string courseCode;
    string title;
    int creditHours;
public:
    Course() : courseCode(""), title(""), creditHours(0) {}
    Course(string code, string title, int creditHours)
        : courseCode(code), title(title), creditHours(0) {
        setCreditHours(creditHours);
    }
    string getCourseCode() const { return courseCode; }
    string getTitle() const { return title; }
    int getCreditHours() const { return creditHours; }
    void setTitle(const string& newTitle) {
        title = newTitle;
    }
    bool setCreditHours(int hours) {
        if (hours < 1 || hours > 6) {
            cout << "Invalid credit hours (must be 1-6).\n";
            return false;
        }
        creditHours = hours;
        return true;
    }
    void display() const {
        cout << courseCode << " | " << title
             << " | Credit Hours: " << creditHours << "\n";
    }
};
class Instructor {
private:
    string instructorId;
    string name;
    string department;
public:
    Instructor() : instructorId(""), name(""), department("") {}
    Instructor(string id, string name, string department)
        : instructorId(id), name(name), department(department) {}
    string getInstructorId() const { return instructorId; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    void setName(const string& newName) {
        if (newName.empty()) {
            cout << "Name cannot be empty.\n";
            return;
        }
        name = newName;
    }
    void setDepartment(const string& newDepartment) {
        department = newDepartment;
    }
    void display() const {
        cout << instructorId << " | " << name
             << " | Department: " << department << "\n";
    }
};
