//
// Created by User on 21.10.2019.
//

using namespace std;

class Coder {

public:
    static string encrypt(string text, string password) {
        while (text.length() > password.length()) password += password;
        int rawEncrText[text.length()];
        string encrText = text;
        int shift = 0b100000;
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') encrText[i] = ' ';
            else {
                rawEncrText[i] = text[i] + (password[i] - 'A');
                if (rawEncrText[i] - 'z' > 0) {
                    encrText[i] = rawEncrText[i] + ('a' - 'z') - shift - 1;
                } else {
                    encrText[i] = rawEncrText[i] - shift;
                }
            }
        }
        return encrText;
    }

    static string decrypt(string text, string password) {
        while (text.length() > password.length()) password += password;
        int rawDecrText[text.length()];
        string decrText = text;
        int shift = 0b100000;

//        cout << "text = " << text << endl;
//        cout << "password = " << password << endl;
        cout << "rawDecrText = " << rawDecrText << endl;
//        cout << "decrText = " << decrText << endl;

        for (int i = 0; i < text.length(); ++i) {

            cout << "i = " << i << endl;
            cout << "text[i] = " << text[i] << " / " << (int) text[i] << endl;
            cout << "password[i] = " << password[i] << " / " << (int) password[i] << endl;
            cout << "'A' = " << 'A' << " / " << (int) 'A' << endl;
            cout << "(password[i] - 'A') = " << (password[i] - 'A') << (int) (password[i] - 'A') << endl;

            if (text[i] == ' ') decrText[i] = ' ';
            else {
                rawDecrText[i] = text[i] - (password[i] - 'A');
                if (rawDecrText[i] - 'z' > 0) {
                    decrText[i] = rawDecrText[i] + ('a' - 'z') - shift - 1;
                } else {
                    decrText[i] = rawDecrText[i] - shift;
                }
            }
            cout << "rawDecrText[i] = " << rawDecrText[i] << " / " << (int) rawDecrText[i] << endl;
            cout << "decrText[i] = " << decrText[i] << " / " << (int) decrText[i] << endl;
            cout << "///////////////////////////////////////////////////////" << endl;
        }
        return decrText;
    }
};

