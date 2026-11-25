#include "MultipleChoiceQuestion.h"
#include "TrueFalseQuestion.h"
#include "CodingQuestion.h"
#include "ShortAnswerQuestion.h"
#include "Quiz.h"

int main() {
    Quiz quiz("QZ-03", "Data Structures Quiz");

    quiz.addQuestion(unique_ptr<Question>(new MultipleChoiceQuestion(
        "Q1", "Which data structure uses LIFO?", 5,
        vector<string>{"Queue", "Stack", "Array", "Tree"}, 'B')));

    quiz.addQuestion(unique_ptr<Question>(new CodingQuestion(
        "Q2", "Write a function that returns the square of n.", 15, "C++",
        vector<string>{"4", "9", "16", "25"})));

    quiz.addQuestion(unique_ptr<Question>(new TrueFalseQuestion(
        "Q3", "The size of an int is always 8 bytes.", 5, false)));

    quiz.addQuestion(unique_ptr<Question>(new ShortAnswerQuestion(
        "Q4", "Which data structure follows FIFO order?", 5,
        vector<string>{"queue"})));

    quiz.displayQuiz();

    vector<string> studentAnswers = {"b", "4,9,16,25", "false", "Queue"};
    quiz.submitQuiz("std_4901", studentAnswers);

    return 0;
}
