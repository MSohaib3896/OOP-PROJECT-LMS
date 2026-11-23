
#include <iostream>
#include <string>
using namespace std;

class Assignment
{
private:
    int assignmentID;

public:
    Assignment() { assignmentID = 0; }
    ~Assignment() {}

    void setID(int id) { assignmentID = id; }
    int getID() { return assignmentID; }

    bool isValidID() { return assignmentID > 0; }

    void display()
    {
        cout << "Assignment ID: " << getID() << endl;
    }
};

class Submission
{
private:
    int studentID;
    string submissionStatus;

public:
    Submission() { studentID = 0; submissionStatus = "Pending"; }
    ~Submission() {}

    void setStudentID(int id) { studentID = id; }
    void setStatus(string status) { submissionStatus = status; }

    int getStudentID() { return studentID; }
    string getStatus() { return submissionStatus; }

    bool isSubmitted() { return submissionStatus == "Submitted"; }

    void submitAssignment(int sID, string status)
    {
        setStudentID(sID);
        setStatus(status);
    }

    void showSubmission()
    {
        cout << "Student ID: " << getStudentID() << endl;
        cout << "Status: " << getStatus() << endl;
    }
};

class Grading
{
private:
    int obtainedMarks;
    string remarks;

public:
    Grading() { obtainedMarks = 0; remarks = "No remarks"; }
    ~Grading() {}

    void setGrade(int marks, string rem)
    {
        obtainedMarks = marks;
        remarks = rem;
    }

    int getMarks() { return obtainedMarks; }
    string getRemarks() { return remarks; }

    bool hasPassed() { return obtainedMarks >= 50; }

    void showGrade()
    {
        cout << "Obtained Marks: " << getMarks() << endl;
        cout << "Teacher Remarks: " << getRemarks() << endl;
    }
};

int main()
{
    Assignment a1;
    a1.setID(101);
    a1.display();

    cout << "------------------" << endl;

    Submission s1;
    s1.submitAssignment(501, "Submitted");
    s1.showSubmission();

    cout << "------------------" << endl;

    Grading g1;
    g1.setGrade(18, "Good work");
    g1.showGrade();

    return 0;
}

