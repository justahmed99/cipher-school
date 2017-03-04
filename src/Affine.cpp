#include "Affine.h"

Affine::Affine(string i, int a, int b)
{
    this->input = i;
    this->a = a;
    this->b = b;
}
int Affine::mod(int x, int y) {
    return ((x % y) + y) % y;
}
int Affine::gcd(int x, int y) {
    if(y != 0) {
        return gcd(y, mod(x, y));
    } else {
        return x;
    }
}
int Affine::mod_inv(int x, int y) {
    int i = 0;
    int r = 0;
    bool o = false;

    while(1) {
        r = mod(x*i, y);
        i++;
        if(r == 1) {
            o = true;
            break;
        } else {
            if(i == y) {
                break;
            }
            o = false;
        }
    }

    if(o) {
        return i-1;
    } else {
        return NULL;
    }
}
void Affine::encrypt(string &s, int &a, int &b) {
    while(gcd(a, 26) != 1) {
        cout << "the a key doesn't meet the requirement. Input again!" << endl;
        cout << "Input a : "; cin >> a;
    }
    while(b > 26) {
        cout << "the b key doesn't meet the requirement. Input again!" << endl;
        cout << "Input b : "; cin >> b;
    }
    char temp[30];
    strcpy(temp, s.c_str());
    for(int i = 0; i < 30; i++) {
        char buff;
        if(temp[i] != '\0') {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                buff = mod((int)(((temp[i] - 'A') * a) + b), 26);
                temp[i] = buff + 'A';
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                buff = mod((int)(((temp[i] - 'a') * a) + b), 26);
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
void Affine::decrypt(string &s, int a, int b) {
    char temp[30];
    strcpy(temp, s.c_str());
    for(int i = 0; i < 30; i++) {
        char buff;
        if(temp[i] != '\0') {
            if(temp[i] >= 'A' && temp[i] <= 'Z') {
                buff = mod((((int)((temp[i] - 'A') - b)) * mod_inv(a, 26)), 26);
                temp[i] = buff + 'A';
            } else if(temp[i] >= 'a' && temp[i] <= 'z') {
                buff = mod((((int)((temp[i] - 'b') - b)) * mod_inv(a, 26)), 26);
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
void Affine::print() {
    encrypt(this->input, this->a, this->b);
    decrypt(this->input, this->a, this->b);
}
