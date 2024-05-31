#include <iostream>
using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

void intro();
void firstRoom();
void secondRoom();
void thirdRoom();
void badEnding();
void goodEnding();

int main() {
    intro();
    return 0;
}

void intro() {
    cout << BLUE << "Welcome to Adventure Game! " << RESET << endl;
    cout << "You find yourself in a dark room with two doors" << endl;
    cout << "Choose wisely to find your way out" << endl << endl;

    firstRoom();
}

void firstRoom() {
    string choice;
    cout << YELLOW << "You are in the First Room. There are two doors, left and right" << RESET << endl;
    cout << "Which door do you choose (left/right): ";
    cin >> choice;

    if (choice == "left") {
        cout << GREEN << "You enter the left door." << RESET << endl << endl;
        secondRoom();
    } else if (choice == "right") {
        cout << RED << "You enter the right door" << RESET << endl << endl;
        badEnding();
    } else {
        cout << "Invalid choice. Please re-enter either 'left' or 'right'." << endl << endl;
        firstRoom();
    }
}

void secondRoom() {
    string choice;
    cout << YELLOW << "You are in the Second Room." << RESET << endl;
    cout << "Do you want to look through the window or go through the door? (window/door): ";
    cin >> choice;

    if (choice == "window") {
        cout << GREEN << "You see a beautiful garden outside." << RESET << endl << endl;
        thirdRoom();
    } else if (choice == "door") {
        cout << RED << "You find yourself back at the first Room." << RESET << endl << endl;
        firstRoom();
    } else {
        cout << "Invalid choice. Please re-enter 'window' or 'door'." << endl;
        secondRoom();
    }
}

void thirdRoom() {
    string choice;
    cout << YELLOW << "You are in the Third Room. There's a key on the table and a locked door" << RESET << endl;
    cout << "Do you take the key or try to open the door without it? (key/door): ";
    cin >> choice;

    if (choice == "key") {
        cout << GREEN << "You take the key and open the door." << RESET << endl << endl;
        goodEnding();
    } else if (choice == "door") {
        cout << RED << "The door is locked. You need a key." << RESET << endl << endl;
        thirdRoom();
    } else {
        cout << "Invalid choice. Please re-enter 'key' or 'door'." << endl;
        thirdRoom();
    }
}

void goodEnding() {
    cout << GREEN << "You opened the door and found your way out." << RESET << endl;
    cout << GREEN << "Congratulations! You won the game!" << RESET << endl;
}

void badEnding() {
    cout << RED << "You entered a room full of traps. You couldn't escape." << RESET << endl;
    cout << RED << "Game Over!" << RESET << endl << endl;
}

