#ifndef AFFINE_H
#define AFFINE_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Affine
{
    public:
        Affine(string i, int a, int b);
        int mod(int x, int y);
        int gcd(int x, int y);
        int mod_inv(int x, int y);
        void encrypt(string &s, int &a, int &b);
        void decrypt(string &s, int a, int b);
        void print();

    protected:

    private:
        string input;
        int a;
        int b;
};

#endif // AFFINE_H
