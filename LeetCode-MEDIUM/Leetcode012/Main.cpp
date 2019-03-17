#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string str = "";
        int digit;
        
        if(num == 0) {
            return str;
        }
        
        //1000
        digit = num/1000;
        num %= 1000;
        str.append(digit,'M');
        //100
        digit = num/100;
        num %= 100;
        if(digit>0 && digit<4) {
            str.append(digit, 'C');
        } else if(digit==4) {
            str.append("CD");
        } else if(digit>4 && digit<9) {
            str.append(1,'D');
            str.append(digit-5, 'C');
       } else if(digit==9) {
            str.append("CM");
        }
        //10
        digit = num/10;
        num %= 10;
        if(digit>0 && digit<4) {
            str.append(digit, 'X');
        } else if(digit==4) {
            str.append("XL");
        } else if(digit>4 && digit<9) {
            str.append(1,'L');
            str.append(digit-5, 'X');
        } else if(digit==9) {
            str.append("XC");
        }
        //1
        digit = num;
        if(digit>0 && digit<4) {
            str.append(digit, 'I');
        } else if(digit==4) {
            str.append("IV");
        } else if(digit>4 && digit<9) {
            str.append(1,'V');
            str.append(digit-5, 'I');
        } else if(digit==9) {
            str.append("IX");
        }
        return str;
    }
};