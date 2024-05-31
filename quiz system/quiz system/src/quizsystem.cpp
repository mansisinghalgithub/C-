#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
protected:
    string text;

public:
    Question(string text) : text(text) {}

    virtual void display() = 0;
    virtual bool checkAnswer(int answer) = 0;
};

class MultipleChoiceQuestion : public Question {
private:
    vector<string> options;
    int correctOption;

public:
    MultipleChoiceQuestion(string text, vector<string> options, int correctOption)
        : Question(text), options(options), correctOption(correctOption) {}

    void display() override {
        cout << text << endl;
        for (int i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int answer) override {
        return answer == correctOption;
    }
};


class Quiz {
private:
    vector<Question*> questions;
    vector<int> scores;

public:
    Quiz() {}

    void addQuestion(Question* q) {
        questions.push_back(q);
    }

    void start() {
        int numUsers;
        cout << "Enter the number of users: ";
        cin >> numUsers;

        scores.resize(numUsers, 0);

        for (int i = 0; i < questions.size(); ++i) {
            questions[i]->display();
            cout << endl;
            for (int j = 0; j < numUsers; ++j) {
                int answer;
                cout << "User " << j + 1 << ", enter your answer: ";
                cin >> answer;

                if (questions[i]->checkAnswer(answer)) {
                    cout << "Correct!" << endl <<endl;
                    scores[j]++;
                } else {
                    cout << "Wrong!" << endl <<endl;
                }
            }
        }


        cout << "Quiz finished! Overall scores:\n";
        for (size_t i = 0; i < scores.size(); ++i) {
            cout << "User " << i + 1 << ": " << scores[i]  << "/" << questions.size() << endl;
        }
    }

    ~Quiz() {
        for (Question* q : questions) {
            delete q;
        }
    }
};

int main() {
	MultipleChoiceQuestion* q1 = new MultipleChoiceQuestion("Identify the correct extension of the user-defined header file in C++?", {".cpp", ".hg", ".h", ".hf"}, 3);
	MultipleChoiceQuestion* q2 = new MultipleChoiceQuestion("Identify the incorrect constructor type?", {"Friend constructor", "Default constructor", "Parameterized constructor", "Copy constructor"}, 1);
	MultipleChoiceQuestion* q3 = new MultipleChoiceQuestion("C++ uses which approach?", {"right-left", "top-down", "left-right", "bottom-up"}, 2);
	MultipleChoiceQuestion* q4 = new MultipleChoiceQuestion("Which data type is supported in C++ but not in C?", {"int", "bool", "double", "float"}, 2);
	MultipleChoiceQuestion* q5 = new MultipleChoiceQuestion("Identify the correct syntax for declaring arrays in C++?", {"array arr[10]", "array{10}", "int arr[10]", "int arr"}, 3);
	MultipleChoiceQuestion* q6 = new MultipleChoiceQuestion("Size of wchar_t is?", {"2", "4", "2 or 4", "Depends on number of bits in system"}, 4);
	MultipleChoiceQuestion* q7 = new MultipleChoiceQuestion("Which of the following is address of operator?", {"*", "&", "[]", "&&"}, 2);
	MultipleChoiceQuestion* q8 = new MultipleChoiceQuestion("Identify the correct example for a pre-increment operator?", {"++n", "n++", "--n", "+n"},1 );
	MultipleChoiceQuestion* q9 = new MultipleChoiceQuestion("Which of the following loops is best when we know the number of iterations?", {"While loop", "Do while", "For loop", "All of above"}, 3);
	MultipleChoiceQuestion* q10 = new MultipleChoiceQuestion("Identify the scope resolution operator?", {":", "::", "?", "None"}, 2);

    Quiz quiz;
    quiz.addQuestion(q1);
    quiz.addQuestion(q2);
    quiz.addQuestion(q3);
    quiz.addQuestion(q4);
    quiz.addQuestion(q5);
    quiz.addQuestion(q6);
    quiz.addQuestion(q7);
    quiz.addQuestion(q8);
    quiz.addQuestion(q9);
    quiz.addQuestion(q10);

    quiz.start();

    return 0;
}
