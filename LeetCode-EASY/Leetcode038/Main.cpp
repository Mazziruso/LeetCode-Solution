#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string str;

    void next() {
        int len = str.length();
        int i = 0;
        int cnt = 1;
        string s = "";
        while(i<len) {
            cnt = 1;
            while(i<len-1 && str[i]==str[i+1]) {
                i++;
                cnt++;
            }
            s += to_string(cnt);
            s += str[i];
            i++;
        }

        str = s;

    }

    string countAndSay(int n) {
        str = '1';

        for(int i=1; i<n; i++) {
            next();
        }

        return str;
    }
};