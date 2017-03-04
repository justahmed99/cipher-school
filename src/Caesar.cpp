#include "Caesar.h"

Caesar::Caesar(string i, int k) {
    this->input = i;
    this->key = k;
}
int Caesar::mod(int x, int y) {
    return ((x % y) + y) % y;
}
void Caesar::encrypt(string &s, int k) {
    char temp[30];
    strcpy(temp, s.c_str());
    for(int i = 0; i < 30; i++) {
        char buff;
        if(temp[i] != '\0') {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                buff = mod((int)((temp[i] - 'A') + k), 26);
                temp[i] = buff + 'A';
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                buff = mod((int)((temp[i] - 'a') + k), 26);
                temp[i] = buff + 'a';
            } else {
                continue;
            }
        } else {
            continue;
        }
    }
    cout << "Encrypt Result : " << temp << endl;
    s = string(temp);
}
void Caesar::decrypt(string &s, int k) {
    char temp[30];
    strcpy(temp, s.c_str());
    for(int i = 0; i < 30; i++) {
        char buff;
        if(temp[i] != '\0') {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                buff = mod((int)((temp[i] - 'A') - k), 26);
                temp[i] = buff + 'A';
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                buff = mod((int)((temp[i] - 'a') - k), 26);
                temp[i] = buff + 'a';
            } else {
                continue;
            }
        } else {
            continue;
        }
    }
    cout << "Decrypt Result : " << temp << endl;
    s = string(temp);
}
void Caesar::print() {
    cout << "Input : " << this->input << endl;
    encrypt(this->input, this->key);
    decrypt(this->input, this->key);
}
