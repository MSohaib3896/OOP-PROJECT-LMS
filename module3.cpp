#include <iostream>
#include <string>
using namespace std;

// 1. Assignment Class
class Assignment {
private:
    int assignmentID;

public:
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
    Assignment a1;
    a1.setAssignmentID(101);
    a1.display();

    cout << "-------------------" << endl;

    // Submission Object
    Submission s1;
    s1.setStudentID(501);
    s1.setSubmissionStatus("Submitted");
    s1.showSubmission();

    cout << "-------------------" << endl;

    // Grading Object
    Grading g1;
    g1.setObtainedMarks(18);
    g1.setRemarks("Good work");
    g1.showGrade();

    return 0;
}
