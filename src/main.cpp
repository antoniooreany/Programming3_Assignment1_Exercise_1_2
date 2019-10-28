#include <iostream>
#include "Coder.h"

int main() {

    string password = "PASSWORT PASSWORT ";

    string textToEncrypt = "vigenere quadrat";
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

    cout << "///////////////////////////////////////////" << endl;

    string answer;
    answer = textToEncrypt.compare(decrText) == 0 ? "CORRECT!" : "INCORRECT!";
    cout << answer << endl;

    return 0;
}
