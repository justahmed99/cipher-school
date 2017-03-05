#ifndef VIGNERE_H
#define VIGNERE_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Vignere
{
    public:
        Vignere(string i, string k);
        int mod(int x, int y);
        void encrypt(string &s, string k);
        void decrypt(string &s, string k);
        void print();

    private:
        string input;
        string key;
};

#endif // VIGNERE_H
