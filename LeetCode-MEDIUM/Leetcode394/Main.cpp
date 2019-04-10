#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int N;
    vector<int> nextB;
    string str;

    string DFS(int s, int e) {
        string res="";
        string inner;
        int k;
        for(int i=s; i<=e; i++) {
            if((str[i]<'0' || str[i]>'9') && str[i]!='[' && str[i]!=']') {
                res += str[i];
            } else {
                k = i;
                while(str[i]!='[') {
                    i++;
                }
                k = stoi(str.substr(k, i-k));
                inner = DFS(i+1, nextB[i]-1);
                while(k--) {
                    res += inner;
                }
                i = nextB[i];
            }
        }
        return res;
    }

    string decodeString(string s) {
        N = s.length();
        str = s;
        nextB.resize(N, 0);
        for(int i=1; i<N; i++) {
            if(s[i]=='[') {
                nextB[i] = i;
            } else if(s[i]==']') {
                nextB[nextB[i-1]] = i;
                nextB[i] = nextB[nextB[i-1]-1];
            } else {
                nextB[i] = nextB[i-1];
            }
        }
        return DFS(0, N-1);
    }
};

int main() {

    cout << Solution().decodeString("3[a]2[b4[F]c]") << endl;

    return 0;
}