#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length()-1;

        while(index>=0 && s[index]==' ') {
            index--;
        }
        int end = index;
        while(index>=0 && s[index]!=' ') {
            index--;
        }
        int start = index;
        return end-start;
    }
};