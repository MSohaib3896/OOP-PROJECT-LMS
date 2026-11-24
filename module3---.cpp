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

// 2. Submission Class
class Submission {
private:
    int studentID;
    string submissionStatus;

public:
    // Default Constructor
    Submission() {
        studentID = 0;
        submissionStatus = "Pending";
    }

    // Parameterized Constructor
    Submission(int sID, string status) {
        studentID = sID;
        submissionStatus = status;
    }

    // Destructor
    ~Submission() {
        cout << "Submission object destroyed (Student ID: " << studentID << ")" << endl;
    }

    // Setters
    void setStudentID(int sID) {
        studentID = sID;
    }

    void setSubmissionStatus(string status) {
        submissionStatus = status;
    }

    // Getters
    int getStudentID() const {
        return studentID;
    }

    string getSubmissionStatus() const {
        return submissionStatus;
    }

    void showSubmission() const {
        cout << "Student ID: " << getStudentID() << endl;
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
    // Assignment Object (using Default Constructor + Setter)
    Assignment a1;
    a1.setAssignmentID(101);
    a1.display();

    cout << "-------------------" << endl;

    // Submission Object (using Parameterized Constructor)
    Submission s1(501, "Submitted");
    s1.showSubmission();

    cout << "-------------------" << endl;

    // Grading Object (using Default Constructor + Setters)
    Grading g1;
    g1.setObtainedMarks(18);
    g1.setRemarks("Good work");
    g1.showGrade();

    cout << "-------------------" << endl;

    return 0;
}
