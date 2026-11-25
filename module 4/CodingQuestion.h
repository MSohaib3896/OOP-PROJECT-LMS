#include <vector>
#include <sstream>
#include "Question.h"
using namespace std;

class CodingQuestion : public Question {
private:
    string language;
    vector<string> expectedOutputs;

    string trim(string s) const {
        int start = s.find_first_not_of(" \t");
        if (start == (int)string::npos) {
            return "";
        }
        int end = s.find_last_not_of(" \t");
        return s.substr(start, end - start + 1);
    }

public:
    CodingQuestion(string id, string questionText, int questionPoints,
                   string lang, vector<string> outputs)
        : Question(id, questionText, questionPoints) {
        language = lang;
        expectedOutputs = outputs;
    }

    int getTotalTestCases() const { return (int)expectedOutputs.size(); }

    int countPassedTests(string studentInput) const {
        vector<string> given;
        stringstream ss(studentInput);
        string piece;

        while (getline(ss, piece, ',')) {
            given.push_back(trim(piece));
        }

        int passed = 0;
        for (int i = 0; i < (int)expectedOutputs.size() && i < (int)given.size(); i++) {
            if (given[i] == expectedOutputs[i]) {
                passed++;
            }
        }
        return passed;
    }

    bool evaluateAnswer(string studentInput) const override {
        if (expectedOutputs.empty()) {
            return false;
        }
        return countPassedTests(studentInput) == (int)expectedOutputs.size();
    }

    string getType() const override {
        return "CodingQuestion";
    }

    void display() const override {
        Question::display();
        cout << "   Language: " << language
             << " | Test cases: " << expectedOutputs.size() << endl;
    }
};