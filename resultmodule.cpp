#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student
{
private:
    int studentID;
    string studentName;

public:
    Student()
    {
        studentID = 0;
        studentName = "Unknown";
        cout << "Student object created." << endl;
    }

    void setStudent(int id, string name)
    {
        studentID = id;
        studentName = name;
    }

    void displayStudent() const
    {
        cout << "Student ID: " << studentID << endl;
        cout << "Student Name: " << studentName << endl;
    }

    int getStudentID() const
    {
        return studentID;
    }

    ~Student()
    {
        cout << "Student object destroyed." << endl;
    }
};

class Result
{
private:
    string subject;
    float marks;
    float totalMarks;

public:
    Result()
    {
        subject = "Not assigned";
        marks = 0;
        totalMarks = 100;
        cout << "Result object created." << endl;
    }

    void setResult(string sub, float obtained, float total)
    {
        subject = sub;
        marks = obtained;
        totalMarks = total;
    }

    float calculatePercentage() const
    {
        if (totalMarks <= 0)
        {
            return 0;
        }
        return (marks / totalMarks) * 100;
    }

    char calculateGrade() const
    {
        float percentage = calculatePercentage();

        if (percentage >= 80)
            return 'A';
        else if (percentage >= 70)
            return 'B';
        else if (percentage >= 60)
            return 'C';
        else if (percentage >= 50)
            return 'D';
        else
            return 'F';
    }

    bool isPassed() const
    {
        return calculatePercentage() >= 50;
    }

    void displayResult() const
    {
        cout << "\n--- Student Result ---" << endl;
        cout << "Subject: " << subject << endl;
        cout << "Marks: " << marks << " / " << totalMarks << endl;
        cout << "Percentage: " << calculatePercentage() << "%" << endl;
        cout << "Grade: " << calculateGrade() << endl;

        if (isPassed())
            cout << "Status: Pass" << endl;
        else
            cout << "Status: Fail" << endl;
    }

    ~Result()
    {
        cout << "Result object destroyed." << endl;
    }
};

int main()
{
    Student student1;
    Result result1;

    int id;
    string name;
    string subject;
    float marks;
    float totalMarks;

    cout << "\nEnter Student ID: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Subject Name: ";
    getline(cin, subject);

    cout << "Enter Obtained Marks: ";
    cin >> marks;

    cout << "Enter Total Marks: ";
    cin >> totalMarks;

    student1.setStudent(id, name);
    result1.setResult(subject, marks, totalMarks);

    cout << "\n--- Student Information ---" << endl;
    student1.displayStudent();
    result1.displayResult();

    return 0;
}
