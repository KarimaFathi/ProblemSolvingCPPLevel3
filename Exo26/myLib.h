#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace myLib {
    string toUpperString(string s1) {
        for (int i = 0; i < s1.length(); i++) {
            s1[i] = toupper(s1[i]);
        }
        return s1;
    }

    string toLowerString(string s1) {
        for (int i = 0; i < s1.length(); i++) {
            s1[i] = tolower(s1[i]);
        }
        return s1;
    }
}


