#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_QUIZZES = 100;
const int MAX_OPTIONS = 4;

struct Question {
    string text;
    string options[MAX_OPTIONS];
    int correctAnswer;
};

struct Quiz {
    Question* questions; // Pointer to questions
    int questionCount;   // Number of questions
};

Quiz* quizzes; // Dynamic array of quizzes
int quizCount = 0;
int quizCapacity = 0;

void addQuiz() {
    if (quizCount >= quizCapacity) {
        quizCapacity = (quizCapacity == 0) ? 1 : quizCapacity * 2; // Double the capacity
        Quiz* newQuizzes = new Quiz[quizCapacity];
        for (int i = 0; i < quizCount; ++i) {
            newQuizzes[i] = quizzes[i]; // Copy existing quizzes
        }
        delete[] quizzes; // Free old memory
        quizzes = newQuizzes; // Update pointer
    }

    cout << "How many questions for this quiz? ";
    int questionCount;
    cin >> questionCount;

    quizzes[quizCount].questions = new Question[questionCount]; // Allocate memory for questions
    quizzes[quizCount].questionCount = questionCount; // Store number of questions

    for (int i = 0; i < questionCount; ++i) {
        cout << "Enter question " << (i + 1) << ": ";
        cin.ignore();
        getline(cin, quizzes[quizCount].questions[i].text);

        for (int j = 0; j < MAX_OPTIONS; ++j) {
            cout << "Enter option " << (j + 1) << ": ";
            getline(cin, quizzes[quizCount].questions[i].options[j]);
        }

        cout << "Enter correct answer (1-4): ";
        cin >> quizzes[quizCount].questions[i].correctAnswer;
    }

    quizCount++;
    cout << "Quiz added!\n";
}

void takeQuiz() {
    cout << "Available quizzes:\n";
    for (int i = 0; i < quizCount; ++i) {
        cout << (i + 1) << ". Quiz " << (i + 1) << endl; // Simple numbering
    }

    cout << "Select a quiz: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > quizCount) {
        cout << "Invalid selection.\n";
        return;
    }

    int correctCount = 0;
    int questionCount = quizzes[choice - 1].questionCount; // Use the stored question count

    for (int i = 0; i < questionCount; ++i) {
        cout << "Question: " << quizzes[choice - 1].questions[i].text << endl;
        for (int j = 0; j < MAX_OPTIONS; ++j) {
            cout << (j + 1) << ". " << quizzes[choice - 1].questions[i].options[j] << endl;
        }

        int answer;
        cout << "Your answer (1-4): ";
        cin >> answer;

        if (answer == quizzes[choice - 1].questions[i].correctAnswer) {
            correctCount++;
        }
    }

    cout << "You got " << correctCount << " out of " << questionCount << " correct.\n";
}

void cleanUp() {
    for (int i = 0; i < quizCount; ++i) {
        delete[] quizzes[i].questions; // Free each quiz's questions
    }
    delete[] quizzes; // Free the quizzes array
}

int main() {
    quizzes = nullptr; // Initialize pointer to null

    while (true) {
        cout << "1. Add Quiz\n2. Take Quiz\n3. Exit\n";
        int option;
        cin >> option;

        switch (option) {
        case 1: addQuiz(); break;
        case 2: takeQuiz(); break;
        case 3: cleanUp(); return 0; // Clean up before exit
        default: cout << "Invalid option.\n"; break;
        }
    }
}