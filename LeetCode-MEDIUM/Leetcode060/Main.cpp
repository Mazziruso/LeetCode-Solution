#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    vector<int> fac;
    vector<int> nums;

    int findNum(int k) {
        int index=0;
        while(index<n && k>0) {
            index++;
            k -= nums[index];
        }
        nums[index] = 0;
        return index;
    }

    string getPermutation(int n, int k) {
        //init
        this->n = n;
        int f=1;
        fac.resize(n,1);
        for(int i=1; i<n; i++) {
            f *= i;
            fac[i] = f;
        }
        nums.resize(n+1,1);

        k--;
        int index;
        int num;
        string res = "";
        for(int i=n-1; i>=1; i--) {
            index = k/(fac[i]);
            num = findNum(index+1);
            res += to_string(num);
            k %= fac[i];
        }
        res += to_string(findNum(1));
        return res;
    }
};

int main() {

    cout << Solution().getPermutation(1,1) << endl;

    return 0;
}