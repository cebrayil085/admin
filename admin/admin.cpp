#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_QUIZZES = 100;
const int MAX_OPTIONS = 4;

struct Quiz {
    string title;
    string questions[MAX_QUIZZES];
    string options[MAX_QUIZZES][MAX_OPTIONS];
    int answers[MAX_QUIZZES];
    int questionCount;
};

Quiz quizzes[MAX_QUIZZES];
int quizCount = 0;

void createQuiz() {
    cout << "Enter quiz title: ";
    cin >> quizzes[quizCount].title;

    cout << "How many questions? ";
    cin >> quizzes[quizCount].questionCount;

    for (int i = 0; i < quizzes[quizCount].questionCount; ++i) {
        cout << "Enter question " << (i + 1) << ": ";
        cin >> quizzes[quizCount].questions[i];

        for (int j = 0; j < MAX_OPTIONS; ++j) {
            cout << "Enter option " << (j + 1) << ": ";
            cin >> quizzes[quizCount].options[i][j];
        }

        cout << "Enter correct answer (1-4): ";
        cin >> quizzes[quizCount].answers[i];
    }

    quizCount++;
    cout << "Quiz created!\n";
}





int main() {
    
}