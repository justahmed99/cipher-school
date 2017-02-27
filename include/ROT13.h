#ifndef ROT13_H
#define ROT13_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class ROT13
{
    public:
        ROT13(string i);
        int mod(int x, int y);
        void encrypt(string &s);
        void decrypt(string &s);
        void print();

    private:
        string input;
};

#endif // ROT13_H
