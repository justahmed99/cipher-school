#ifndef CAESAR_H
#define CAESAR_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Caesar
{
    public:
        Caesar(string i, int k);
        int mod(int x, int y);
        void encrypt(string &s, int k);
        void decrypt(string &s, int k);
        void print();

    private:
        string input;
        int key;
};

#endif // CAESAR_H
