#include <iostream>
#include <string>
using namespace std;

class Result
{
private:
    int studentID;
    string subject;
    float marks;

public:
    void setResult(int id, string sub, float m)
    {
        studentID = id;
        subject = sub;
        marks = m;
    }
    void displayResult()
    {
        cout << "\n--- Student Result ---" << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Subject: " << subject << endl;
        cout << "Marks: " << marks << endl;

        if (marks >= 50)
        {
            cout << "Status: Pass" << endl;
        }
        else
        {
            cout << "Status: Fail" << endl;
        }
    }
};

int main()
{
    Result r1;

    int id;
    string subject;
    float marks;

    cout << "Enter Student ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Subject Name: ";
    getline(cin, subject);

    cout << "Enter Marks: ";
    cin >> marks;
    r1.setResult(id, subject, marks);
    r1.displayResult();

    return 0;
}
