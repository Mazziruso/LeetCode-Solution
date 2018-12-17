#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	int len;
	string str;
	vector<string> res;
	vector<string> letterCasePermutation(string S) {
		str = S;
		len = str.length();
		convertUL(0);
		return res;
	}
	void convertUL(int index) {
		if (index >= len) {
			res.push_back(str);
			return;
		}

		convertUL(index + 1);
		if (str[index] >= 'A' && str[index] <= 'Z') {
			str[index] = str[index] - 'A' + 'a';
			convertUL(index + 1);
			str[index] = str[index] - 'a' + 'A';
		}
		else if (str[index] >= 'a' && str[index] <= 'z') {
			str[index] = str[index] - 'a' + 'A';
			convertUL(index + 1);
			str[index] = str[index] - 'A' + 'a';
		}
	}
};

int main() {

	string str = "dasd";

	Solution s;

	vector<string> res = s.letterCasePermutation(str);

	for (auto ss : res) {
		cout << ss << ", ";
	}
	cout << endl;
	system("pause");
	return 0;
}