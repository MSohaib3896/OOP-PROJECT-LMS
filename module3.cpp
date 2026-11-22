#include <iostream>
#include <string>
using namespace std;

class Assignment
{
private:
    int assignmentID;

public:
    void setID(int id)
    {
        assignmentID = id;
    }

    void display()
    {
        cout << "Assignment ID: " << assignmentID << endl;
    }
};

class Submission
{
private:
    int studentID;
    string submissionStatus;

public:
    void submitAssignment(int sID, string status)
    {
        studentID = sID;
        submissionStatus = status;
    }

    void showSubmission()
    {
        cout << "Student ID: " << studentID << endl;
        cout << "Status: " << submissionStatus << endl;
    }
};

class Grading
{
private:
    int obtainedMarks;
    string remarks;

public:
    void setGrade(int marks, string rem)
    {
        obtainedMarks = marks;
        remarks = rem;
    }

    void showGrade()
    {
        cout << "Obtained Marks: " << obtainedMarks << endl;
        cout << "Teacher Remarks: " << remarks << endl;
    }
};

int main()
{
    Assignment a1;
    a1.setID(101);
    a1.display();

    cout << "-------------------" << endl;

    Submission s1;
    s1.submitAssignment(501, "Submitted");
    s1.showSubmission();

    cout << "-------------------" << endl;

    Grading g1;
    g1.setGrade(18, "Good work");
    g1.showGrade();

    return 0;
}
