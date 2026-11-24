
#include <iostream>
#include <string>
using namespace std;

// 1. Assignment Class
class Assignment {
private:
    int assignmentID;

public:
    // Default Constructor
    Assignment() {
        assignmentID = 0;
    }

    // Parameterized Constructor
    Assignment(int id) {
        assignmentID = id;
    }

    // Destructor
    ~Assignment() {
        cout << "Assignment object destroyed (ID: " << assignmentID << ")" << endl;
    }

    // Setter
    void setAssignmentID(int id) {
        assignmentID = id;
    }

    // Getter
    int getAssignmentID() const {
        return assignmentID;
    }

    void display() const {
        cout << "Assignment ID: " << getAssignmentID() << endl;
    }
};

// 2. Submission Class (Updated with Student Name & Roll Number)
class Submission {
private:
    string studentName;
    string rollNo;
    string submissionStatus;

public:
    // Default Constructor
    Submission() {
        studentName = "Unknown";
        rollNo = "N/A";
        submissionStatus = "Pending";
    }

    // Parameterized Constructor
    Submission(string name, string rNo, string status) {
        studentName = name;
        rollNo = rNo;
        submissionStatus = status;
    }

    // Destructor
    ~Submission() {
        cout << "Submission object destroyed (" << studentName << ")" << endl;
    }

    // Setters
    void setStudentName(string name) {
        studentName = name;
    }

    void setRollNo(string rNo) {
        rollNo = rNo;
    }

    void setSubmissionStatus(string status) {
        submissionStatus = status;
    }

    // Getters
    string getStudentName() const {
        return studentName;
    }

    string getRollNo() const {
        return rollNo;
    }

    string getSubmissionStatus() const {
        return submissionStatus;
    }

    void showSubmission() const {
        cout << "Student Name: " << getStudentName() << endl;
        cout << "Roll No: " << getRollNo() << endl;
        cout << "Status: " << getSubmissionStatus() << endl;
    }
};

// 3. Grading Class
class Grading {
private:
    int obtainedMarks;
    string remarks;

public:
    // Default Constructor
    Grading() {
        obtainedMarks = 0;
        remarks = "No remarks";
    }

    // Parameterized Constructor
    Grading(int marks, string rem) {
        obtainedMarks = marks;
        remarks = rem;
    }

    // Destructor
    ~Grading() {
        cout << "Grading object destroyed (Marks: " << obtainedMarks << ")" << endl;
    }

    // Setters
    void setObtainedMarks(int marks) {
        obtainedMarks = marks;
    }

    void setRemarks(string rem) {
        remarks = rem;
    }

    // Getters
    int getObtainedMarks() const {
        return obtainedMarks;
    }

    string getRemarks() const {
        return remarks;
    }

    void showGrade() const {
        cout << "Obtained Marks: " << getObtainedMarks() << endl;
        cout << "Teacher Remarks: " << getRemarks() << endl;
    }
};

// Main Function
int main() {
    // Assignment Object
    Assignment a1(101);
    a1.display();
    cout << "===============================" << endl;

    // 5 Students Data Arrays (Submissions & Grades)
    Submission students[5] = {
        Submission("Namra Imran", "f202533202", "Submitted"),
        Submission("Sohaib", "f202533201", "Submitted"),
        Submission("Nawaira Mushtaq", "f202533205", "Submitted"),
        Submission("Rabiya Imtiaz", "f202533204", "Submitted"),
        Submission("Maham Mohsin", "f202533203", "Submitted")
    };

    Grading grades[5] = {
        Grading(19, "Excellent work"),
        Grading(18, "Good work"),
        Grading(20, "Outstanding"),
        Grading(17, "Well done"),
        Grading(18, "Good effort")
    };

    // Display all 5 students' records
    for (int i = 0; i < 5; i++) {
        cout << "Student #" << (i + 1) << endl;
        students[i].showSubmission();
        grades[i].showGrade();
        cout << "-------------------------------" << endl;
    }

    return 0;
}
