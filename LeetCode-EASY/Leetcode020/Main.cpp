#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
	stack<char> parentheses;
	char countpart(char c) {
		char res;
		switch (c) {
		case '(':
			res = ')';
			break;
		case '{':
			res = '}';
			break;
		case '[':
			res = ']';
			break;
		default:
			res = ')';
		}
		return res;
	}
	bool isValid(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				parentheses.push(countpart(s[i]));
			}
			else if(!parentheses.empty()) {
				if (s[i] != parentheses.top()) {
					return false;
				}
				else {
					parentheses.pop();
				}
			} else {
                return false;
            }
		}
		return parentheses.empty();
	}
};