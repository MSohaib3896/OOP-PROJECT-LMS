#include <cctype>
#include "Question.h"
using namespace std;

class TrueFalseQuestion : public Question {
private:
    bool correctAnswer;

    string toLower(string s) const {
        for (int i = 0; i < (int)s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }

public:
    TrueFalseQuestion(string id, string questionText, int questionPoints, bool correct)
        : Question(id, questionText, questionPoints) {
        correctAnswer = correct;
    }

    bool getCorrectAnswer() const { return correctAnswer; }

    bool evaluateAnswer(string studentInput) const override {
        string answer = toLower(studentInput);

        if (answer == "true" || answer == "t") {
            return correctAnswer == true;
        }
        if (answer == "false" || answer == "f") {
            return correctAnswer == false;
        }
        return false;
    }

    string getType() const override {
        return "TrueFalse";
    }
};