#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
using namespace std;

class Question {
private:
    string questionId;
    string text;
    int points;

public:
    Question(string id, string questionText, int questionPoints) {
        questionId = id;
        text = questionText;
        setPoints(questionPoints);
    }

    virtual ~Question() {}

    string getId() const { return questionId; }
    string getText() const { return text; }
    int getPoints() const { return points; }

    void setPoints(int newPoints) {
        if (newPoints > 0) {
            points = newPoints;
        } else {
            points = 1; 
        }
    }

    virtual bool evaluateAnswer(string studentInput) const = 0;
    virtual string getType() const = 0;

    virtual void display() const {
        cout << "[" << getType() << "] " << text
             << " (" << points << " pts)" << endl;
    }
};

#endif