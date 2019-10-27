#include <iostream>
#include "Coder.h"

int main() {

    string password = "PASSWORT PASSWORT ";

    string textToEncrypt = "zjhhjk vigenere quadrat";
//    string textToEncrypt = "vigenere quadrat";
    string encrText = Coder::encrypt(textToEncrypt, password);
    cout << "textToEncrypt = " << textToEncrypt << endl;
    cout << "password = " << password << endl;
    cout << "encrText = " << encrText << endl;

    cout << "///////////////////////////////////////////" << endl;

    string textToDecrypt = encrText;
    string decrText = Coder::decrypt(textToDecrypt, password);
    cout << "textToDecrypt = " << textToDecrypt << endl;
    cout << "password = " << password << endl;
    cout << "decrText = " << decrText << endl;

    return 0;
}
