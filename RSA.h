#include <stdio.h>
#include <iostream>
#include <string>

class RSA {
    private:
        int p;
        int q;
        string message;
        long long[] openKey;
        long long[] secretKey;
    public:
        RSA() {};
        RSA(string, int, int, int);
        ~RSA() {};
        int phi();
        string encode();
        string decode();
        void setMessage(string);
        void setQ(int);
        void setP(int);
        string getMessage();
        int getQ();
        int getP();
}
