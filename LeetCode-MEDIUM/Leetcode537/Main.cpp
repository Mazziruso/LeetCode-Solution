#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		pair<int, int> m1 = extractNum(a);
		pair<int, int> m2 = extractNum(b);
		return to_string(m1.first*m2.first - m1.second*m2.second) + '+' + to_string(m1.first*m2.second + m1.second*m2.first) + 'i';
	}
	pair<int, int> extractNum(string a) {
		int i, q;
		string str;
		int index = a.find_first_of('+');
		i = stoi(a.substr(0, index));
		q = (a[index + 1] == 'i') ? 1 : stoi(a.substr(index + 1, (a.length() - index - 2)));
		return pair<int, int>(i, q);
	}
};

int main() {
	Solution s;
	cout << s.complexNumberMultiply("1+i", "1+1i") << endl;
	system("pause");
	return 0;
}
