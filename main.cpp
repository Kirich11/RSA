#include "RSA.h"

int main() {

    int a, b;
    RSA *key = new RSA;
    cout<<"start"<<endl;
    do {
        cout<<"Введите 2 различных числа не больше 100"<<endl;
        cin>>a;
        cin>>b;
    } while (a>=100 && b>=100 && a==b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    
    key->setQ(key->eratosphen(a));
    key->setP(key->eratosphen(b));

    cout<<"Первое простое число: "<<key->getQ()<<endl;
    cout<<"Второе простое число: "<<key->getP()<<endl;
    
    key->formKeys();

    cout<<"Число m: "<<key->getM()<<endl;
    cout<<"Число n: "<<key->getN()<<endl;

    cout << '{' << setw(12) << key->getPublicKey() << ',' << setw(12) << key->getN() << '}' << " - Open key" << endl;
    cout << '{' << setw(12) << key->getSecretKey() << ',' << setw(12) << key->getN() << '}' << " - Secret key" << endl << endl;
    const int MAX = 20;
    string text;
    cout<<"Введите числа для шифрования (max 20)"<<endl;
    cin>>text;
    cout<<"Введенный текст: "<<text<<endl;

    /* d*e = 1+ k*M проверка ключей. При p=3, q=7 k=76 
    cout<<key->getSecretKey()*key->getPublicKey()<<" "<<1+76*key->getM()<<endl;
    */

    double crypto;
    double decrypt;

    crypto = key->encode(atoi(text.c_str()));
    decrypt = key->decode(crypto);

    cout << setw(5) << text << setw(6) << text << setw(20)
    << crypto << setw(14) << decrypt << endl;

    return 0;
}