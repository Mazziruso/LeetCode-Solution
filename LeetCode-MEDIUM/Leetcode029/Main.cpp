#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        if(dividend < divisor) {
            return 0;
        }
        long long k = divisor;
        long long cnt = 1;
        while((k+k) <= dividend) {
            k += k;
            cnt += cnt;
        }
        return cnt + divide(dividend-k, divisor);
    }
    int divide(int dividend, int divisor) {
        bool sign = (dividend>=0 && divisor>0) || (dividend<=0 && divisor<0);
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        long long cnt = divide(ldividend, ldivisor);
        if(cnt >= INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        } else {
            return sign ? cnt : -cnt;
        }
    }
};