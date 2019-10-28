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
/**
 * Encrypts the text.
 * @param text is a text to be encrypted.
 * @param password is a password for the encryption.
 * @return an enrrypted text.
 */
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
                    encrText[i] = rawEncrText[i] - SHIFT_LOWER_TO_UPPER + (A_LOWER - Z_LOWER) - 1;
                }
            }
        }
        return encrText;
    }

/**
 * Decrypts the text.
 * @param text is a text to be decrypted.
 * @param password is a password for the encryption.
 * @return a derypted text.
 */
    static string decrypt(string text, string password) {
        getNormalizedPassword(text, password);
        int rawText[text.length()];
        string decrText = text;
        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') decrText[i] = ' ';
            else {
                int decrTextCh = 0;
                int charInRange = getIsInRange(text[i], password[i], rawText, i, decrTextCh);
                if ((text[i] - Z_LOWER + SHIFT_LOWER_TO_UPPER <= 0) && charInRange) {
                    decrText[i] = getDecrChar(text[i], password[i], rawText, i);
                }
                int textCh = text[i] - (A_LOWER - Z_LOWER) + 1;
                charInRange = getIsInRange(textCh, password[i], rawText, i, decrTextCh);
                if ((text[i] - A_LOWER + SHIFT_LOWER_TO_UPPER + 1 > 0) && charInRange) {
                    decrText[i] = getDecrChar(textCh, password[i], rawText, i);
                }
            }
        }
        return decrText;
    }

/**
 * Checks if the char in the range.
 * @param textCh is a character for chacking.
 * @param passwordCh is a character of the password.
 * @param rawText is a raw text to check.
 * @param i is an index.
 * @param decrTextCh.
 * @return true if dectypted chatate in the range, falser if a dectypted chatate if ont inthe range.
 */
    static bool getIsInRange(const char &textCh, const char &passwordCh, int *rawText, int i, int decrTextCh) {
        decrTextCh = getDecrChar(textCh, passwordCh, rawText, i);
        bool charInRange = (decrTextCh >= A_LOWER && decrTextCh <= Z_LOWER);
        return charInRange;
    }

/**
 * Produses a dectypted character.
 * @param textCh is a chatacter to be decrypted.
 * @param passwordCh is a password for dectyption.
 * @param rawText is a raw after be decryption.
 * @param i is an index.
 * @return a decrypted text.
 */
    static int getDecrChar(const char &textCh, const char &passwordCh, int *rawText, int i) {
        rawText[i] = textCh + SHIFT_LOWER_TO_UPPER;
        int decrTextCh = rawText[i] - (passwordCh - A_UPPER);
        return decrTextCh;
    }

    /**
     * Normalises the password.
     * @param text is a text for normalization.
     * @param password is the original password.
     * @return normalized password.
     */
    static string &getNormalizedPassword(const string &text, string &password) {
        while (text.length() > password.length()) password += password;
        if (password.size() > text.size()) password = password.substr(0, text.size());
        return password;
    }
};

