#include <iostream>
#include "Caesar.h"
#include "ROT13.h"

using namespace std;

void intro();
void menu();
int main() {
    intro();
    menu();
    int choice;
    cout << "Make your choice : "; cin >> choice;
    switch(choice) {
        case 1 : {
            cout << "---- Caesar ----" << endl;
            string input;
            int key;
            cout << "Input string : "; cin >> input;
            cout << "Input key    : "; cin >> key;
            Caesar *c = new Caesar(input, key);
            c->print();
            break;
        }
        case 2 : {
            cout << "---- ROT13 ----" << endl;
            string input;
            cout << "Input string : "; cin >> input;
            ROT13 *r = new ROT13(input);
            r->print();
            break;
        }
        default : {
            cout << "Your choice isn't found" << endl;
        }
    }


    return 0;
}
void intro() {
    cout << "Welcome to Cipher School" << endl
    << "-----------------------------------------------------" << endl
    << "This program is an open-source program" << endl
    << "to learn how the cipher programs work." << endl
    << "You can learn freely from the source code and also " << endl
    << "you can use the demo here." << endl
    << "Enjoy your learning time ! :)" << endl
    << "-----------------------------------------------------" << endl
    << endl << endl;
}
void menu() {
    cout << "---- Cipher Menu ----" << endl;
    cout << "1. Caesar" << endl;
    cout << "2. ROT13" << endl;
}
