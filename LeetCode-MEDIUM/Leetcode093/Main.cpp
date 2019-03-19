#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int len;
    string s;
    string ip;
    vector<string> res;
    bool isValid(string str) {
        int num = stoi(str);
        if(num==0 && str.size()>1) {
            return false;
        } else if(num>0 && str[0]=='0') {
            return false;
        } else {
            return num<256;
        }
    }
    void DFS(int index, int seg) {
        if(len-index > 16-3*seg) {
            return;
        }
        if(seg>4 && index<len-1) {
            return;
        }
        if(seg>4 && index==len-1) {
            res.push_back(ip);
            return;
        }
        string str;
        string tmp = ip;
        for(int i=index+1; i<len && i<index+4; i++) {
            str += s[i];
            if(isValid(str)) {
                ip += str;
                if(seg<4) {
                    ip += '.';
                }
                DFS(i, seg+1);
                ip = tmp;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        this->len = s.size();
        if(len<4) {
            return res;
        }
        this->s = s;
        this->ip = "";
        DFS(-1, 1);
        return res;
    }
};


int main() {

    vector<string> res = Solution().restoreIpAddresses("0000");

    for(auto s : res) {
        cout << s << endl;
    }

    return 0;
}