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

int main()
{
    Assignment a1;
    a1.setID(101);
    a1.display();

    cout << "-------------------" << endl;

    Submission s1;
    s1.submitAssignment(501, "Submitted");
    s1.showSubmission();

    return 0;
}



