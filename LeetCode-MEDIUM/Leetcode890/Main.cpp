#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	unordered_map<char, char>::iterator iter1;
	unordered_map<char, char>::iterator iter2;
	unordered_map<char, char> p2w;
	unordered_map<char, char> w2p;
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;
		for (auto str : words) {
			if (matched(str, pattern)) {
				res.push_back(str);
			}
		}
		return res;
	}
	bool matched(string word, string pattern) {
		if (word.length() != pattern.length()) {
			return false;
		}
		int len = word.length();
		p2w.clear();
		w2p.clear();
		for (int i = 0; i < len; i++) {
			iter1 = p2w.find(pattern[i]);
			iter2 = w2p.find(word[i]);
			if (iter1 == p2w.end() && iter2 == w2p.end()) {
				p2w[pattern[i]] = word[i];
				w2p[word[i]] = pattern[i];
			}
			else if (iter1 == p2w.end() && iter2 != w2p.end() || iter1 != p2w.end() && iter2 == w2p.end()) {
				return false;
			}
			else if (iter1->second != word[i] || iter2->second != pattern[i]) {
				return false;
			}
		}
		return true;
	}
};
