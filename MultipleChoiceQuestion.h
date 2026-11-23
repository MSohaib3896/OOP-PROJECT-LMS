#include <vector>
#include <cctype>
#include "Question.h"
using namespace std;
class MultipleChoiceQuestion : public Question {
private:
    vector<string> options;
    char correctOption;
public:
    MultipleChoiceQuestion(string id, string questionText, int questionPoints,
                           vector<string> questionOptions, char correct)
        : Question(id, questionText, questionPoints) {
        options = questionOptions;
        setCorrectOption(correct);
    }
    void setCorrectOption(char correct) {
        char upper = toupper(correct);
        int index = upper - 'A';
        if (index >= 0 && index < (int)options.size()) {
            correctOption = upper;
        } else {
            correctOption = 'A';
        }
    }
    char getCorrectOption() const { return correctOption; }
    bool evaluateAnswer(string studentInput) const override {
        if (studentInput.empty()) {
            return false;
        }
        char answer = toupper(studentInput[0]);
        return answer == correctOption;
    }
    string getType() const override {
        return "MultipleChoice";
    }
    void display() const override {
        Question::display();
        for (int i = 0; i < (int)options.size(); i++) {
            cout << "   " << char('A' + i) << ") " << options[i] << endl;
        }
    }
};