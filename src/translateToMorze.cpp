#include "translateToMorze.hpp"

#define BUZZER_PIN A4

char MorzeAlphabet[][7] = {
    //*Array was written, according to basic ASCII coding table
    /*
    0 - 31st symbols was not added, because they are used to control the process of 
    text output on display or printer, or beeping, or doing something else.
    */

    {1, 1, 1, 1, 1, 1, 1}, //space - 32
    {2, 1, 2, 1, 2, 2, 0}, // ! - 33
    {1, 2, 1, 1, 2, 1, 0}, // " - 34
    {0, 0, 0, 0, 0, 0, 0}, // # - 35
    {1, 1, 1, 2, 1, 1, 2}, // $ - 36
    {0, 0, 0, 0, 0, 0, 0}, // % - 37
    {1, 2, 1, 1, 1, 0, 0}, // & - 38
    {1, 2, 2, 2, 2, 1, 0}, // ' - 39
    {2, 1, 2, 2, 1, 0, 0}, // ( - 40
    {2, 1, 2, 2, 1, 2, 0}, // ) - 41
    {0, 0, 0, 0, 0, 0, 0}, // * - 42
    {1, 2, 1, 2, 1, 0, 0}, // + - 43
    {1, 2, 1, 2, 1, 2, 0}, // , - 44
    {2, 1, 1, 1, 1, 2, 0}, // - - 45
    {1, 1, 1, 1, 1, 1, 0}, // . - 46
    {2, 1, 1, 2, 1, 0, 0}, // / - 47
    {2, 2, 2, 2, 2, 0, 0}, // 0 - 48
    {1, 2, 2, 2, 2, 0, 0}, // 1 - 49
    {1, 1, 2, 2, 2, 0, 0}, // 2 - 50
    {1, 1, 1, 2, 2, 0, 0}, // 3 - 51
    {1, 1, 1, 1, 2, 0, 0}, // 4 - 52
    {1, 1, 1, 1, 1, 0, 0}, // 5 - 53
    {2, 1, 1, 1, 1, 0, 0}, // 6 - 54
    {2, 2, 1, 1, 1, 0, 0}, // 7 - 55
    {2, 2, 2, 1, 1, 0, 0}, // 8 - 56
    {2, 2, 2, 2, 1, 0, 0}, // 9 - 57
    {2, 2, 2, 1, 1, 1, 0}, // : - 58
    {2, 1, 2, 1, 2, 1, 0}, // ; - 59
    {0, 0, 0, 0, 0, 0, 0}, // < - 60
    {2, 1, 1, 1, 2, 0, 0}, // = - 61
    {0, 0, 0, 0, 0, 0, 0}, // > - 62
    {1, 1, 2, 2, 1, 1, 0}, // ? - 63
    {1, 2, 2, 1, 2, 1, 0}, // @ - 64
    {1, 2, 0, 0, 0, 0, 0}, // A - 65
    {2, 1, 1, 1, 0, 0, 0}, // B - 66
    {2, 1, 2, 1, 0, 0, 0}, // C - 67
    {2, 1, 1, 0, 0, 0, 0}, // D - 68
    {1, 0, 0, 0, 0, 0, 0}, // E - 69
    {1, 1, 2, 1, 0, 0, 0}, // F - 70
    {2, 2, 1, 0, 0, 0, 0}, // G - 71
    {1, 1, 1, 1, 0, 0, 0}, // H - 72
    {1, 1, 0, 0, 0, 0, 0}, // I - 73
    {1, 2, 2, 2, 0, 0, 0}, // J - 74
    {2, 1, 2, 0, 0, 0, 0}, // K - 75
    {1, 2, 1, 1, 0, 0, 0}, // L - 76
    {2, 2, 0, 0, 0, 0, 0}, // M - 77
    {2, 1, 0, 0, 0, 0, 0}, // N - 78
    {2, 2, 2, 0, 0, 0, 0}, // O - 79
    {1, 2, 2, 1, 0, 0, 0}, // P - 80
    {2, 2, 1, 2, 0, 0, 0}, // Q - 81
    {1, 2, 1, 0, 0, 0, 0}, // R - 82
    {1, 1, 1, 0, 0, 0, 0}, // S - 83
    {2, 0, 0, 0, 0, 0, 0}, // T - 84
    {1, 1, 2, 0, 0, 0, 0}, // U - 85
    {1, 1, 1, 2, 0, 0, 0}, // V - 86
    {1, 2, 2, 0, 0, 0, 0}, // W - 87
    {2, 1, 1, 2, 0, 0, 0}, // X - 88
    {2, 1, 2, 2, 0, 0, 0}, // Y - 89
    {2, 2, 1, 1, 0, 0, 0}, // Z - 90
    {0, 0, 0, 0, 0, 0, 0}, // [ - 91
    {0, 0, 0, 0, 0, 0, 0}, // \ - 92
    {0, 0, 0, 0, 0, 0, 0}, // ] - 93
    {0, 0, 0, 0, 0, 0, 0}, // ^ - 94
    {1, 1, 2, 2, 1, 2, 0}, // _ - 95
    {2, 2, 1, 1, 2, 2, 0}, // ` - 96
    {1, 2, 0, 0, 0, 0, 0}, // a - 97
    {2, 1, 1, 1, 0, 0, 0}, // b - 98
    {2, 1, 2, 1, 0, 0, 0}, // c - 99
    {2, 1, 1, 0, 0, 0, 0}, // d - 100
    {1, 0, 0, 0, 0, 0, 0}, // e - 101
    {1, 1, 2, 1, 0, 0, 0}, // f - 102
    {2, 2, 1, 0, 0, 0, 0}, // g - 103
    {1, 1, 1, 1, 0, 0, 0}, // h - 104
    {1, 1, 0, 0, 0, 0, 0}, // i - 105
    {1, 2, 2, 2, 0, 0, 0}, // j - 106
    {2, 1, 2, 0, 0, 0, 0}, // k - 107
    {1, 2, 1, 1, 0, 0, 0}, // l - 108
    {2, 2, 0, 0, 0, 0, 0}, // m - 109
    {2, 1, 0, 0, 0, 0, 0}, // n - 110
    {2, 2, 2, 0, 0, 0, 0}, // o - 111
    {1, 2, 2, 1, 0, 0, 0}, // p - 112
    {2, 2, 1, 2, 0, 0, 0}, // q - 113
    {1, 2, 1, 0, 0, 0, 0}, // r - 114
    {1, 1, 1, 0, 0, 0, 0}, // s - 115
    {2, 0, 0, 0, 0, 0, 0}, // t - 116
    {1, 1, 2, 0, 0, 0, 0}, // u - 117
    {1, 1, 1, 2, 0, 0, 0}, // v - 118
    {1, 2, 2, 0, 0, 0, 0}, // w - 119
    {2, 1, 1, 2, 0, 0, 0}, // x - 120
    {2, 1, 2, 2, 0, 0, 0}, // y - 121
    {2, 2, 1, 1, 0, 0, 0}, // z - 122
    {0, 0, 0, 0, 0, 0, 0}, // { - 123
    {0, 0, 0, 0, 0, 0, 0}, // | - 124
    {0, 0, 0, 0, 0, 0, 0}, // } - 125
    {0, 0, 0, 0, 0, 0, 0}, // ~ - 126
    //127th ASCII symbol was not added, because it's DELETE symbol
};

TranslateToMorze::TranslateToMorze(int frequency,
                                   int dotDelay)
{
    _freq = frequency;
    _dotDelay = dotDelay;

    pinMode(BUZZER_PIN, OUTPUT);
}

void TranslateToMorze::dot()
{
    tone(BUZZER_PIN, _freq, _dotDelay);
    delay(_dotDelay);
}

void TranslateToMorze::dash()
{
    tone(BUZZER_PIN, _freq, _dotDelay * 3);
    delay(_dotDelay);
}

void TranslateToMorze::playEndOfTheLetter()
{
    delay(_dotDelay * 2);
}

void TranslateToMorze::playLetter(char letter)
{
    for (int i = 0; i < 7; i++)
    {
        Serial.println("Entered for() cycle");
        if (MorzeAlphabet[letter - 32][i] == 2) //*32 is an ASCII number of space
        {
            Serial.println("dash");
            dash();
        }
        if (MorzeAlphabet[letter - 32][i] == 1) //*32 is an ASCII number of space
        {
            Serial.println("dot");
            dot();
        }
        Serial.println("Left for() cycle");
    }
}

void TranslateToMorze::playAllMessages(char * message1, char* message2)
{
    for (size_t i = 0; i < strlen(message1); i++)
    {
        playLetter(message1[i]);
        playEndOfTheLetter();
    }
    Serial.println("Played 1st string");
    for (size_t i = 0; i < strlen(message2); i++)
    {
        playLetter(message2[i]);
        playEndOfTheLetter();
    }
    Serial.println("Played 2nd string");
}