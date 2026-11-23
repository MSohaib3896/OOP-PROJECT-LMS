#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
class Course {
private:
    std::string courseCode;
    std::string title;
    int creditHours;
public:
    Course() : courseCode(""), title(""), creditHours(0) {}

    Course(std::string code, std::string title, int creditHours)
        : courseCode(code), title(title), creditHours(0) {
        setCreditHours(creditHours);
    }
    std::string getCourseCode() const { return courseCode; }
    std::string getTitle() const { return title; }
    int getCreditHours() const { return creditHours; }
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }
    bool setCreditHours(int hours) {
        if (hours < 1 || hours > 6) {
            std::cout << "Invalid credit hours (must be 1-6).\n";
            return false;
        }
        creditHours = hours;
        return true;
    }
    void display() const {
        std::cout << courseCode << " | " << title
                  << " | Credit Hours: " << creditHours << "\n";
    }
};

#endif
