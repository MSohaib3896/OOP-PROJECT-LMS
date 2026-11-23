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
