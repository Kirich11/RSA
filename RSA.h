#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;

class RSA {
    private:
        int p; // first prime number
        int q; // second prime number
        int m; // divider
        int n; // second part of the keys
        int secretKey;
        int publicKey;
    public:
        RSA() {};
        RSA(int, int);
        ~RSA() {};        
        double encode(int);
        double decode(double);
        void setQ(int);
        void setP(int);
        void formKeys();
        int getSecretKey();
        int getPublicKey();
        int getQ();
        int getP();
        int getM();
        int getN();
        int eratosphen(int);
        int gcd(int, int);
        int ASCIItranslate(char);
};
