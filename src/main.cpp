#include <iostream>
#include "Coder.h"

int main() {

//    string text = "vigenere quadrat";
//    string password = "PASSWORT PASSWOR";
//    string decrText = Coder::encrypt(text, password);
//    cout << "text = " << text << endl;
//    cout << "password = " << password << endl;
//    cout << "decrText = " << decrText << endl;


    string text = "KIYWJSIX FUSVNOK";
    string password = "PASSWORT PASSWOR";
    string decrText = Coder::decrypt(text, password);
    cout << "text = " << text << endl;
    cout << "password = " << password << endl;
    cout << "decrText = " << decrText << endl;

    return 0;
}
