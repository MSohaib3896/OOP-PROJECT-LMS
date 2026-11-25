#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Instructor {
private:
    string instructorId;         
    string name;
    string department;

    static void requireText(const string& value, const string& field) {
        if (value.empty())
            throw invalid_argument(field + " cannot be empty");
    }
public:
    Instructor(const string& id, const string& name, const string& department)
        : instructorId(id), name(name), department(department) {
        requireText(id, "Instructor ID");
        requireText(name, "Instructor name");
        requireText(department, "Department");
    }

    string getInstructorId() const { return instructorId; }
    string getName() const { return name; }
    string getDepartment() const { return department; }

    void setName(const string& newName) {
        requireText(newName, "Instructor name");
        name = newName;
    }

    void setDepartment(const string& newDepartment) {
        requireText(newDepartment, "Department");
        department = newDepartment;
    }

    void display() const {
        cout << instructorId << " | " << name
             << " | Department: " << department << "\n";
    }
};

class Course {
private:
    static const int MIN_CREDITS = 1;
    static const int MAX_CREDITS = 6;

    string courseCode;             
    string title;
    int creditHours;
    vector<string> prerequisites;    
    string instructorId;            

public:
    Course(const string& code, const string& title, int creditHours)
        : courseCode(code), title(title), creditHours(MIN_CREDITS) {
        if (code.empty())
            throw invalid_argument("Course code cannot be empty");
        if (title.empty())
            throw invalid_argument("Course title cannot be empty");
        if (!setCreditHours(creditHours))
            throw invalid_argument("Credit hours must be between 1 and 6");
    }

    string getCourseCode() const { return courseCode; }
    string getTitle() const { return title; }
    int getCreditHours() const { return creditHours; }
    string getInstructorId() const { return instructorId; }
    bool hasInstructor() const { return !instructorId.empty(); }

    const vector<string>& getPrerequisites() const { return prerequisites; }

    bool setTitle(const string& newTitle) {
        if (newTitle.empty()) return false;
        title = newTitle;
        return true;
    }

    bool setCreditHours(int hours) {
        if (hours < MIN_CREDITS || hours > MAX_CREDITS) return false;
        creditHours = hours;
        return true;
    }

    bool assignInstructor(const string& id) {
        if (id.empty()) return false;
        instructorId = id;
        return true;
    }

    void removeInstructor() { instructorId.clear(); }

    bool hasPrerequisite(const string& code) const {
        return find(prerequisites.begin(), prerequisites.end(), code)
               != prerequisites.end();
    }

    bool addPrerequisite(const string& code) {
        if (code.empty() || code == courseCode || hasPrerequisite(code))
            return false;
        prerequisites.push_back(code);
        return true;
    }

    bool removePrerequisite(const string& code) {
        vector<string>::iterator it =
            find(prerequisites.begin(), prerequisites.end(), code);
        if (it == prerequisites.end()) return false;
        prerequisites.erase(it);
        return true;
    }

    void display() const {
        cout << courseCode << " | " << title
             << " | Credit Hours: " << creditHours
             << " | Instructor: " << (hasInstructor() ? instructorId : "TBA")
             << "\n";
        if (!prerequisites.empty()) {
            cout << "    Prerequisites: ";
            for (size_t i = 0; i < prerequisites.size(); ++i)
                cout << prerequisites[i]
                     << (i + 1 < prerequisites.size() ? ", " : "\n");
        }
    }
};

class CourseRegistry {
private:
    vector<Course> courses;
    vector<Instructor> instructors;

    int courseIndex(const string& code) const {
        for (size_t i = 0; i < courses.size(); ++i)
            if (courses[i].getCourseCode() == code) return (int)i;
        return -1;
    }

    int instructorIndex(const string& id) const {
        for (size_t i = 0; i < instructors.size(); ++i)
            if (instructors[i].getInstructorId() == id) return (int)i;
        return -1;
    }

    bool reaches(const string& from, const string& target,
                 vector<string>& visited) const {
        if (from == target) return true;
        if (find(visited.begin(), visited.end(), from) != visited.end())
            return false;
        visited.push_back(from);

        int idx = courseIndex(from);
        if (idx < 0) return false;

        const vector<string>& prereqs = courses[idx].getPrerequisites();
        for (size_t i = 0; i < prereqs.size(); ++i)
            if (reaches(prereqs[i], target, visited)) return true;
        return false;
    }

public:
    bool addInstructor(const Instructor& ins) {
        if (instructorIndex(ins.getInstructorId()) >= 0) return false;
        instructors.push_back(ins);
        return true;
    }

    bool addCourse(const Course& c) {
        if (courseIndex(c.getCourseCode()) >= 0) return false;  
        courses.push_back(c);
        return true;
    }

    bool hasCourse(const string& code) const { return courseIndex(code) >= 0; }

    bool findCourse(const string& code, Course& out) const {
        int i = courseIndex(code);
        if (i < 0) return false;
        out = courses[i];
        return true;
    }

    bool addPrerequisite(const string& courseCode, const string& prereqCode) {
        int ci = courseIndex(courseCode);
        if (ci < 0 || courseIndex(prereqCode) < 0) return false;

        vector<string> visited;
        if (reaches(prereqCode, courseCode, visited)) return false;  

        return courses[ci].addPrerequisite(prereqCode);
    }

    bool assignInstructor(const string& courseCode, const string& instructorId) {
        int ci = courseIndex(courseCode);
        if (ci < 0 || instructorIndex(instructorId) < 0) return false;
        return courses[ci].assignInstructor(instructorId);
    }

    size_t courseCount() const { return courses.size(); }

    void displayAll() const {
        cout << "=== Course Registry ===\n";
        for (size_t i = 0; i < courses.size(); ++i) courses[i].display();
        cout << "=== Instructors ===\n";
        for (size_t i = 0; i < instructors.size(); ++i) instructors[i].display();
    }
};

static void report(const string& what, bool ok) {
    cout << (ok ? "[OK]   " : "[FAIL] ") << what << "\n";
}

int main() {
    CourseRegistry registry;

    registry.addInstructor(Instructor("I01", "Dr. Ahmed", "Computer Science"));
    registry.addInstructor(Instructor("I02", "Dr. Sara", "Mathematics"));

    registry.addCourse(Course("CS101", "Intro to Programming", 3));
    registry.addCourse(Course("CS201", "Data Structures", 4));
    registry.addCourse(Course("CS301", "Algorithms", 3));

    cout << "--- Valid operations ---\n";
    report("CS201 requires CS101", registry.addPrerequisite("CS201", "CS101"));
    report("CS301 requires CS201", registry.addPrerequisite("CS301", "CS201"));
    report("Assign I01 to CS101", registry.assignInstructor("CS101", "I01"));

    cout << "\n--- Invalid operations (should all FAIL) ---\n";
    report("Duplicate course CS101", registry.addCourse(Course("CS101", "Copy", 3)));
    report("Duplicate prerequisite", registry.addPrerequisite("CS201", "CS101"));
    report("Self prerequisite", registry.addPrerequisite("CS101", "CS101"));
    report("Unknown prerequisite", registry.addPrerequisite("CS201", "XX999"));
    report("Circular (CS101 requires CS301)", registry.addPrerequisite("CS101", "CS301"));
    report("Unknown instructor", registry.assignInstructor("CS201", "I99"));

    cout << "\n--- Constructor validation ---\n";
    try {
        Course bad("CS999", "Bad Course", 99);
    } catch (const invalid_argument& e) {
        cout << "Caught: " << e.what() << "\n";
    }
    try {
        Instructor bad("I03", "", "Physics");
    } catch (const invalid_argument& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    cout << "\n";
    registry.displayAll();
    return 0;
}
