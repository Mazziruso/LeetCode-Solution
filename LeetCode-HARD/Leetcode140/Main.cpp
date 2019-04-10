#include<iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<string> combine(string word, vector<string> pre) {
        for(int i=pre.size()-1; i>=0; i--) {
            pre[i] += " " + word;
        }
        return pre;
    }
    vector<string> DFS(string s, unordered_set<string>& dict) {
        if(map.count(s)) {
            return map[s];
        }

        vector<string> res;
        if(dict.count(s)) {
            res.push_back(s);
        }

        vector<string> pre;
        string word;
        for(int i=s.length()-1; i>=0; i--) {
            word = s.substr(i);
            if(dict.count(word)) {
                pre = combine(word, DFS(s.substr(0,i), dict));
                res.insert(res.end(), pre.begin(), pre.end());
            }
        }
        map[s] = res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return DFS(s, dict);
    }
};

int main() {

    string s = "aaa";
    vector<string> words({"a", "aa", "aaa"});

    vector<string> res = Solution().wordBreak(s, words);

    for(auto str : res) {
        cout << str <<endl;
    }

    return 0;
}