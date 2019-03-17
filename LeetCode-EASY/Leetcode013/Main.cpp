#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int toNum(char c) {
        int num = 1;
        switch(c) {
            case 'I':
                num = 1;
                break;
            case 'V':
                num = 5;
                break;
            case 'X':
                num = 10;
                break;
            case 'L':
                num = 50;
                break;
            case 'C':
                num = 100;
                break;
            case 'D':
                num = 500;
                break;
            case 'M':
                num = 1000;
                break;
            default:
                num = 1;
        }
        return num;
    }
    int romanToInt(string s) {
        int len = s.length();
        int num = 0;
        int i = 0;
        while(i < (len-1)) {
            if(toNum(s[i]) >= toNum(s[i+1])) {
                num += toNum(s[i]);
            } else {
                num += toNum(s[i+1]) - toNum(s[i]);
                i++;
            }
            i++;
        }
        if(i<len) {
            num += toNum(s[i]);
        }
        return num;
    }
};