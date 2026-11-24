#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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

        void setName(string n) {
        if (n != "") {
            name = n;
        }
    }
    void setRollNo(string r) {
        if (r != "") {
            rollNo = r;
        }
    }
    void display() const {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
        ~Student() {
    }
};
class AttendanceRecord {
private:
    string rollNo;
    string date;
    bool present;

public:
    AttendanceRecord(string r, string d, bool p) {
        rollNo = r;
        date = d;
        present = p;
    }
    string getRollNo() const { return rollNo; }
    string getDate() const { return date; }
    bool isPresent() const { return present; }

    void display() const {
        cout << date << " | " << rollNo << " | "
             << (present ? "Present" : "Absent") << endl;
    }
};

class Section {
private:
    string courseName;
    string sectionName;
    int capacity;
    vector<Student> students;
    vector<AttendanceRecord> attendance;

    bool isEnrolled(const string& rollNo) const {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getRollNo() == rollNo) {
                return true;
            }
        }
        return false;
    }

public:
    Section(string course, string section, int cap) {
        courseName = course;
        sectionName = section;
        capacity = (cap > 0) ? cap : 1;
    }
    void displayInfo() const {
        cout << courseName << " | Section: " << sectionName
             << " | Capacity: " << capacity << endl;
    }
        bool isFull() const {
        return (int)students.size() >= capacity;
    }


    bool enrollStudent(const Student& s) {
        if (isFull()) {
            cout << "[FAILED] Section is full. Cannot enroll "
                 << s.getName() << "." << endl;
            return false;
        }


        students.push_back(s);
        cout << "[OK] " << s.getName() << " enrolled in "
             << courseName << " (Section " << sectionName << ")." << endl;
        return true;
    }

      void displayStudents() const {
        cout << "\n" << string(50, '=') << endl;
        cout << " " << courseName << " | Section " << sectionName << endl;
        cout << " Seats filled: " << students.size() << "/" << capacity << endl;
        cout << string(50, '=') << endl;
        cout << left << setw(5) << "No." << setw(25) << "Name"
             << "Roll No" << endl;
        cout << string(50, '-') << endl;
        for (size_t i = 0; i < students.size(); i++) {
            cout << left << setw(5) << (i + 1)
                 << setw(25) << students[i].getName()
                 << students[i].getRollNo() << endl;
        }
        cout << string(50, '=') << endl;
    }
        bool markAttendance(string rollNo, string date, bool present) {
        if (!isEnrolled(rollNo)) {
            cout << "[FAILED] " << rollNo
                 << " is not enrolled in this section." << endl;
            return false;
        }
        attendance.push_back(AttendanceRecord(rollNo, date, present));
        return true;
    }

    void displayAttendance() const {
        cout << "\n--- Attendance Log: " << courseName
             << " (Section " << sectionName << ") ---" << endl;
        for (size_t i = 0; i < attendance.size(); i++) {
            attendance[i].display();
        }
    }

        string getCourseName() const { return courseName; }
    string getSectionName() const { return sectionName; }
    int getCapacity() const { return capacity; }
    int getEnrolledCount() const { return (int)students.size(); }

        void setCapacity(int cap) {
        if (cap > 0 && cap >= (int)students.size()) {
            capacity = cap;
        } else {
            cout << "[FAILED] Invalid capacity." << endl;
        }
    }
        ~Section() {
        cout << "Section " << sectionName << " destroyed." << endl;
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

    cout << "===== UMT LMS - Enrollment Portal =====" << endl;

    Section sec("Object Oriented Programming", "D1", 5);
    sec.displayInfo();

    sec.enrollStudent(s1);
    sec.enrollStudent(s2);
    sec.enrollStudent(s3);
    sec.enrollStudent(s4);
    sec.enrollStudent(s5);
    sec.enrollStudent(s6);
    sec.enrollStudent(s7);

    sec.displayStudents();

    s7.setRollNo("F202533208");
    s7.setName("");
    s7.display();

    cout << "Enrolled: " << sec.getEnrolledCount()
         << "/" << sec.getCapacity() << endl;
    sec.setCapacity(2);
    sec.setCapacity(6);
    cout << "New capacity: " << sec.getCapacity() << endl;

    cout << "\n--- Attendance Test ---" << endl;
    AttendanceRecord a1("F202533201", "24-11-2026", true);
    AttendanceRecord a2("F202533202", "24-11-2026", false);
    a1.display();
    a2.display();
        cout << "\n--- Section Attendance ---" << endl;
    sec.markAttendance("F202533201", "24-11-2026", true);
    sec.markAttendance("F202533202", "24-11-2026", false);
    sec.markAttendance("F202533203", "24-11-2026", true);
    sec.markAttendance("F202533206", "24-11-2026", true);   // not enrolled, fails
    sec.displayAttendance();

    return 0;
}
