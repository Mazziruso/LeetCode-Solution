#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector> 

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> bits;
		bits.push_back(0);
		if (num == 0) {	
			return bits;
		}
		bits.push_back(1);
		if (num == 1) {	
			return bits;
		}
		int radix = 1;
		int digit = 1;
		for (int i = 2; i <= num; i++) {
			if (radix == digit) {
				bits.push_back(1);
				radix = i;
				digit = 1;
			}
			else {
				bits.push_back(bits[radix] + bits[digit]);
				digit++;
			}
		}
		return bits;
	}
};

class Solution1 {
public:
	vector<int> countBits(int num) {
		vector<int> bits;
		bits.push_back(0);
		for (int i = 1; i <= num; i++) {
			bits.push_back(bits[i >> 1] + (i & 1));
		}
		return bits;
	}
};

int main() {

	Solution1 s;

	auto res = s.countBits(100);

	for (auto i : res) {
		cout << i << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}