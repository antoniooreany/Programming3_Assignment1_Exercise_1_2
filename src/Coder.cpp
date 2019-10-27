//
// Created by User on 21.10.2019.
//

#include <mshtmlc.h>

using namespace std;

class Coder {

    static char const A_UPPER = 'A';
    static char const A_LOWER = 'a';
    static char const Z_LOWER = 'z';

    static int const SHIFT_LOWER_TO_UPPER = 0b100000;

public:
    static string encrypt(const string &text, string &password) {
        password = getNormalizedPassword(text, password);

        int rawEncrText[text.length()];
        string encrText = text;
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') encrText[i] = ' ';
            else {

                rawEncrText[i] = text[i] + (password[i] - A_UPPER);
                if (rawEncrText[i] - Z_LOWER <= 0) {
                    encrText[i] = rawEncrText[i] - SHIFT_LOWER_TO_UPPER;
                } else {
                    encrText[i] = rawEncrText[i] + (A_LOWER - Z_LOWER) - SHIFT_LOWER_TO_UPPER - 1;
                }
            }
        }
        return encrText;
    }

    static string decrypt(string text, string password) {
        getNormalizedPassword(text, password);

        int rawText[text.length()];
        string decrText = text;
        bool charInRange1 = false;
        bool charInRange2 = false;

        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') decrText[i] = ' ';
            else {
                int decrTextCh = 0;
                charInRange1 = getIsInRange1(text, password, rawText, i, decrTextCh);
                if ((text[i] - Z_LOWER + SHIFT_LOWER_TO_UPPER <= 0) && charInRange1) {
                    rawText[i] = text[i] + SHIFT_LOWER_TO_UPPER;
                    decrText[i] = rawText[i] - (password[i] - A_UPPER);
//                    decrTextCh = getDecrChar1(text, password, rawText, i);

                }

                charInRange2 = getIsInRange2(text, password, rawText, i, decrTextCh);
                if ((text[i] - A_LOWER + SHIFT_LOWER_TO_UPPER + 1 > 0) && charInRange2) {
                    rawText[i] = text[i] - (A_LOWER - Z_LOWER) + SHIFT_LOWER_TO_UPPER + 1;
                    decrText[i] = rawText[i] - (password[i] - A_UPPER);

                }
            }
        }
        return decrText;
    }

    static bool getIsInRange1(const string &text, const string &password, int *rawText, int i, int decrTextCh) {
        decrTextCh = getDecrChar1(text, password, rawText, i);
        bool charInRange = (decrTextCh >= A_LOWER && decrTextCh <= Z_LOWER);
        return charInRange;
    }

    static bool getIsInRange2(const string &text, const string &password, int *rawText, int i, int decrTextCh) {
        decrTextCh = getDecrChar2(text, password, rawText, i);
        bool charInRange = (decrTextCh >= A_LOWER && decrTextCh <= Z_LOWER);
        return charInRange;
    }

    static int getDecrChar1(const string &text, const string &password, int *rawText, int i) {
        rawText[i] = text[i] + SHIFT_LOWER_TO_UPPER;
        int decrTextCh = rawText[i] - (password[i] - A_UPPER);
        return decrTextCh;
    }

    static int getDecrChar2(const string &text, const string &password, int *rawText, int i) {
        rawText[i] = text[i] - (A_LOWER - Z_LOWER) + SHIFT_LOWER_TO_UPPER + 1;
        int decrTextCh = rawText[i] - (password[i] - A_UPPER);
        return decrTextCh;
    }

    static string &getNormalizedPassword(const string &text, string &password) {
        while (text.length() > password.length()) password += password;
        if (password.size() > text.size()) {
            password = password.substr(0, text.size());
        }
        return password;
    }
};

