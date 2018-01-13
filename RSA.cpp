#include "RSA.h"

RSA::RSA(int p, int q) {
    this->p = p;
    this->q = q;
}

double RSA::encode(int s) {
    double c = (double) s;
    c = pow(s, (double) this->getPublicKey());
    cout<<"a^e: "<<c<<endl;
    c = fmod(c, (double) this->getN());
    cout<<"a^e mod n: "<<c<<endl;
    return c;
}

double RSA::decode(double s) {
    double message;
    message = pow(s,(double) this->getSecretKey());
    cout<<"b^d: "<<message<<endl;
    message = fmod(m, (double) this->getN());
    cout<<"b^d mod n: "<<message<<endl;
    return message;
}

void RSA::setQ(int q) {
    this->q = q;
}

void RSA::setP(int p) {
    this->p = p;
}

int RSA::getQ() {
    return this->q;
}

int RSA::getP() {
    return this->p;
}

int RSA::getM() {
    return this->m;
}

int RSA::getN() {
    return this->n;
}

int RSA::getSecretKey() {
    return this->secretKey;
}

int RSA::getPublicKey() {
    return this->publicKey;
}

void RSA::formKeys() {

    int m = (this->getP() - 1)*(this->getQ() - 1);
    int n = (this->getP())*(this->getQ());

    int d, d_simple = 0;    
    while (d_simple != 1) {
        d = rand() % 100;
        d_simple = this->gcd(d, m);
    }
    
    unsigned int e = 0, e_simple = 0;
    while (e_simple !=1)
    {
        e += 1;
        e_simple = (e*d)%(m);
    }

    this->m = m;
    this->n = n;
    this->secretKey = d;
    this->publicKey = e;
}

int RSA::eratosphen(int n){
    int *a = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
      a[i] = i;
    for (int p = 2; p < n + 1; p++)
    {
      if (a[p] != 0)
      {
        for (int j = p*p; j < n + 1; j += p)
          a[j] = 0;
      }
    }
    for(int i = n-1; i >= 1; i--) {
        if(a[i] != 0)
        {
            return a[i];
            break;
        }
    }
}

int RSA::gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int RSA::ASCIItranslate(char c) {
    return int(c); 
}