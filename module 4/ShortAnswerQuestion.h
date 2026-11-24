#include <vector>
#include <cctype>
#include "Question.h"
using namespace std;

class ShortAnswerQuestion : public Question {
private:
    vector<string> acceptedAnswers;

    string normalize(string s) const {
        int start = s.find_first_not_of(" \t");
        if (start == (int)string::npos) {
            return "";
        }
        int end = s.find_last_not_of(" \t");
        s = s.substr(start, end - start + 1);

        for (int i = 0; i < (int)s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }

public:
    ShortAnswerQuestion(string id, string questionText, int questionPoints,
                        vector<string> answers)
        : Question(id, questionText, questionPoints) {
        acceptedAnswers = answers;
    }

    int getAcceptedAnswerCount() const { return (int)acceptedAnswers.size(); }

    bool evaluateAnswer(string studentInput) const override {
        string given = normalize(studentInput);

        if (given.empty()) {
            return false;
        }

        for (int i = 0; i < (int)acceptedAnswers.size(); i++) {
            if (given == normalize(acceptedAnswers[i])) {
                return true;
            }
        }
        return false;
    }

    string getType() const override {
        return "ShortAnswer";
    }
};