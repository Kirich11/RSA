#include 'RSA.h';

RSA::RSA(string message, int p, int q) {
    this->message = message;
    this->p = p;
    this->q = q;
}

int RSA::phi() {
    return (this->p - 1)(this->q - 1);
}

string RSA::encode() {
    
}

string RSA::decode() {

}

void RSA::setMessage(string message) {
    this->message = message;
}

void RSA::setQ(int q) {
    this->q = q;
}

void RSA::setP(int p) {
    this->p = p;
}

string RSA::getMessage() {
    return this->message;
}

int RSA::getQ() {
    return this->q;
}

int RSA::getP() {
    return this->p;
}