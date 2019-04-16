#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;

class Solution {
public:
    unordered_map<ll, int> indices;
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) {
            return "0";
        }
        string res = ((numerator>0) ^ (denominator>0)) ? "-" : "";
        ll num = llabs(numerator);
        ll den = llabs(denominator);
        res += to_string(num/den);
        if(num%den==0) {
            return res;
        }

        num %= den;
        res += '.';
        int pos = res.length();
        while(num) {
            if(indices.find(num)!=indices.end()) {
                res.insert(indices[num], 1, '(');
                res += ')';
                break;
            }
            indices[num] = pos++;
            num *= 10;
            res += to_string(num/den);
            num = num%den;
        }
        return res;
    }
};

int main() {

    cout << Solution().fractionToDecimal(-1,-2147483648) << endl;

    return 0;
}
