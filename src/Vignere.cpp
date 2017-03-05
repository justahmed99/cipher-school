#include "Vignere.h"

Vignere::Vignere(string i, string k)
{
    this->input = i;
    this->key = k;
}
int Vignere::mod(int x, int y) {
    return ((x % y) + y) % y;
}
void Vignere::encrypt(string &s, string k) {
    char temp[256];
    strcpy(temp, input.c_str());
    char ky[256];
    strcpy(ky, key.c_str());
    for(int i = 0, j = 0; i < strlen(temp); i++, j++) {
        if(j >= strlen(ky)) {
            j = 0;
        }
        char buff = temp[i];
        if(temp[i] >= 'A' && temp[i] <= 'Z') {
            buff = mod((int)((temp[i] - 'A') + (ky[j] - 'A')), 26);
            temp[i] = buff + 'A';
        } else if(temp[i] >= 'a' && temp[i] <= 'z') {
            buff = mod((int)((temp[i] - 'a') + (ky[j] - 'a')), 26);
            temp[i] = buff + 'a';
        } else {
            continue;
        }
    }
    s = string(temp);
    cout << "Encrypt Result : " << s << endl;
}
void Vignere::decrypt(string &s, string k) {
    char temp[256];
    strcpy(temp, input.c_str());
    char ky[256];
    strcpy(ky, key.c_str());
    for(int i = 0, j = 0; i < strlen(temp); i++, j++) {
        if(j >= strlen(ky)) {
            j = 0;
        }
        char buff = temp[i];
        if(temp[i] >= 'A' && temp[i] <= 'Z') {
            buff = mod((int)((temp[i] - 'A') - (ky[j] - 'A')), 26);
            temp[i] = buff + 'A';
        } else if(temp[i] >= 'a' && temp[i] <= 'z') {
            buff = mod((int)((temp[i] - 'a') - (ky[j] - 'a')), 26);
            temp[i] = buff + 'a';
        } else {
            continue;
        }
    }
    s = string(temp);
    cout << "Decrypt Result : " << s << endl;
}
void Vignere::print() {
    encrypt(this->input, this->key);
    decrypt(this->input, this->key);
}
