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

void displayQuizzes() {
    cout << "Available quizzes:\n";
    for (int i = 0; i < quizCount; ++i) {
        cout << (i + 1) << ". " << quizzes[i].title << endl;
    }
}

void takeQuiz() {
    displayQuizzes();
    cout << "Select a quiz: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > quizCount) {
        cout << "Invalid selection.\n";
        return;
    }

    Quiz selectedQuiz = quizzes[choice - 1];
    int correctCount = 0;

    for (int i = 0; i < selectedQuiz.questionCount; ++i) {
        cout << "Question: " << selectedQuiz.questions[i] << endl;
        for (int j = 0; j < MAX_OPTIONS; ++j) {
            cout << (j + 1) << ". " << selectedQuiz.options[i][j] << endl;
        }

        int answer;
        cout << "Your answer (1-4): ";
        cin >> answer;

        if (answer == selectedQuiz.answers[i]) {
            correctCount++;
        }
    }

    cout << "You got " << correctCount << " out of " << selectedQuiz.questionCount << " correct.\n";
}

int main() {
    while (true) {
        cout << "1. Create Quiz\n2. Take Quiz\n3. Exit\n";
        int option;
        cin >> option;

        switch (option) {
        case 1: createQuiz(); break;
        case 2: takeQuiz(); break;
        case 3: return 0;
        default: cout << "Invalid option.\n"; break;
        }
    }

}