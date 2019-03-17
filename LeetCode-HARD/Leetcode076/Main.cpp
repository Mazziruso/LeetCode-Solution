#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> pattern;
    vector<int> aB;
    queue<char> letters;
    queue<int> pos;

    void preProcess(string &t) {
        int m = t.length();
        for(int i=0; i<m; i++) {
            pattern[t[i]]++;
        }
    }

    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int index = 0;
        int cnt = 0;

        if(m==0) {
            return "";
        }

        pattern.resize(128,0);
        aB.resize(128,0);
        char c;

        preProcess(t);

        while(index<n && cnt<m) {
            if(pattern[s[index]]>0) {
                letters.push(s[index]);
                pos.push(index);
                aB[s[index]]++;
                cnt += (aB[s[index]]<=pattern[s[index]]) ? 1 : 0;
            }
            c = letters.empty() ? '\r' : letters.front();
            while(aB[c]>pattern[c]) {
                letters.pop();
                pos.pop();
                aB[c]--;
                c = letters.empty() ? '\r' : letters.front();
            }
            index++;
        }

        //no window
        if(cnt < m) {
            return "";
        }

        int start = pos.front();
        int end = pos.back();
        int minLen = end-start;

        for(; index<n; index++) {
            if(pattern[s[index]]>0) {
                letters.push(s[index]);
                pos.push(index);
                aB[s[index]]++;
            }
            c = letters.empty() ? '\r' : letters.front();
            while(aB[c]>pattern[c]) {
                letters.pop();
                pos.pop();
                aB[c]--;
                c = letters.empty() ? '\r' : letters.front();
            }
            if(minLen>(pos.back()-pos.front())) {
                start = pos.front();
                end = pos.back();
                minLen = end-start;
            }
        }
        return s.substr(start,minLen+1);
    }
    string minWindow2(string s, string t) {
        vector<int> map(128,0);
        int cnt = t.length();
        int begin = 0;
        int end = 0;
        int head = 0;
        int d = INT_MAX;
        //initial
        for(char c : t) {
            map[c]++;
        }
        //
        while(end<s.length()) {
            if(map[s[end++]]-- == 0) {
                cnt--;
            }
            while(cnt==0) {
                if(d>end-begin) {
                    d = end - begin;
                    head = begin;
                }
                if(map[s[begin++]]++ == 0) {
                    cnt++;
                }
            }
        }
        return d==INT_MAX ? "" : s.substr(head, d);
    }
};

int main() {
    
    string s = "a";
    string t = "";

    string res = Solution().minWindow(s, t);

    cout << res << endl;

    return 0;
}