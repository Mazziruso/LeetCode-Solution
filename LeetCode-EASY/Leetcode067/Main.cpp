#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:

    char carry;

    char addB(char a, char b) {
        if(a=='0' && b=='0') {
            carry = '0';
            return '0';
        } else if(a=='1' && b=='0') {
            carry = '0';
            return '1';
        } else if(a=='0' && b=='1') {
            carry = '0';
            return '1';
        } else {
            carry = '1';
            return '0';
        }
    }

    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();

        string res = "";
        char c;
        char carry_tmp;
        int i=n-1;
        int j=m-1;
        carry = '0';
        while(i>=0 && j>=0) {
            c = addB(a[i--],carry);
            carry_tmp = carry;
            res += addB(c, b[j--]);
            carry = carry_tmp=='1' ? '1' : carry;
        }
        while(i>=0) {
            res += addB(a[i--], carry);
        }
        while(j>=0) {
            res += addB(b[j--], carry);
        }
        string ret = carry=='1' ? "1" : "";
        for(int i=res.length()-1; i>=0; i--) {
            ret += res[i];
        }
        return ret;
    }
};

int main() {

    cout << Solution().addBinary("1111", "1111110101") << endl;

    return 0;
}