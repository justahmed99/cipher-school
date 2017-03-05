#include "ROT13.h"

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

ROT13::ROT13(string i) {
    this->input = i;
}
int ROT13::mod(int x, int y) {
    return ((x % y) + y) % y;
}
void ROT13::encrypt(string &s) {
    char temp[30];
    strcpy(temp, s.c_str());
    for(int i = 0; i < 30; i++) {
        char buff;
        if(temp[i] != '\0') {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                buff = mod((int)((temp[i] - 'A') + 13), 26);
                temp[i] = buff + 'A';
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                buff = mod((int)((temp[i] - 'a') + 13), 26);
                temp[i] = buff + 'a';
            } else {
                continue;
            }
        } else {
            continue;
        }
    }
    s = string(temp);
    cout << "Encrypt Result : " << s << endl;
}
void ROT13::decrypt(string &s) {
    char temp[30];
    strcpy(temp, s.c_str());
    for(int i = 0; i < 30; i++) {
        char buff;
        if(temp[i] != '\0') {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                buff = mod((int)((temp[i] - 'A') - 13), 26);
                temp[i] = buff + 'A';
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                buff = mod((int)((temp[i] - 'a') - 13), 26);
                temp[i] = buff + 'a';
            } else {
                continue;
            }
        } else {
            continue;
        }
    }
    s = string(temp);
    cout << "Decrypt Result : " << s << endl;
}
void ROT13::print() {
    cout << "Input : " << this->input << endl;
    encrypt(this->input);
    decrypt(this->input);
}
