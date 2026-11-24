#include <vector>
#include <memory>
#include <utility>
#include <iomanip>
#include "Question.h"
using namespace std;

class Quiz {
private:
    string quizId;
    string title;
    vector<unique_ptr<Question> > questions;

public:
    Quiz(string id, string quizTitle) {
        quizId = id;
        title = quizTitle;
    }

    string getQuizId() const { return quizId; }
    string getTitle() const { return title; }
    int getQuestionCount() const { return (int)questions.size(); }

    void addQuestion(unique_ptr<Question> q) {
        questions.push_back(move(q));
    }

    int getTotalPoints() const {
        int total = 0;
        for (int i = 0; i < (int)questions.size(); i++) {
            total += questions[i]->getPoints();
        }
        return total;
    }

    void displayQuiz() const {
        cout << "=== " << title << " (" << quizId << ") ===" << endl;
        for (int i = 0; i < (int)questions.size(); i++) {
            cout << "Q" << (i + 1) << ". ";
            questions[i]->display();
        }
        cout << endl;
    }

    int submitQuiz(string studentId, const vector<string>& answers) const {
        cout << "$ --submit-quiz --student " << studentId
             << " --quiz " << quizId << endl;

        int score = 0;

        for (int i = 0; i < (int)questions.size(); i++) {
            string answer = "";
            if (i < (int)answers.size()) {
                answer = answers[i];
            }

            bool correct = questions[i]->evaluateAnswer(answer);
            int earned = 0;
            if (correct) {
                earned = questions[i]->getPoints();
            }
            score += earned;

            cout << "> Evaluating Q" << (i + 1) << " ["
                 << questions[i]->getType() << "]: "
                 << (correct ? "CORRECT" : "WRONG")
                 << " (+" << earned << " pts)" << endl;
        }

        int total = getTotalPoints();
        double percent = 0;
        if (total > 0) {
            percent = (double)score / total * 100;
        }

        cout << "> Quiz Score: " << score << "/" << total
             << " (" << fixed << setprecision(0) << percent << "%)"
             << " -> Ready for Gradebook." << endl;

        return score;
    }
};