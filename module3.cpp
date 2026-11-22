
#include <iostream>
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

int main()
{
    Assignment a1;

    a1.setID(101);
    a1.display();

    return 0;
}



