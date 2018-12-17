#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	pair<int, int> otime;
	vector<string> res;
	vector<string> readBinaryWatch(int num) {
		if (num >= 9) {
			return res;
		}
		BTH(num, 0, 3);
		return res;
	}

	void BTH(int n, int Htime, int ni) {
		if (Htime > 11) {
			return;
		}
		if (n < 0) {
			return;
		}
		if (n == 0) {
			otime.first = Htime;
			otime.second = 0;
			ostringstream ostr;
			ostr << Htime << ":00";
			res.push_back(ostr.str());
			return;
		}
		if (n > 0) {
			otime.first = Htime;
			BTM(n, 0, 5);
		}

		int pow2;
		for (int i = ni; i >= 0; i--) {
			pow2 = (i > 0) ? (2 << (i - 1)) : 1;
			BTH(n - 1, Htime + pow2, i - 1);
		}
	}

	void BTM(int n, int Mtime, int ni) {
		if (Mtime > 59) {
			return;
		}
		if (n < 0) {
			return;
		}
		if (n == 0) {
			otime.second = Mtime;
			ostringstream ostr;
			ostr << otime.first << ":" << setfill('0') << setw(2) << otime.second;
			res.push_back(ostr.str());
			return;
		}

		int pow2;
		for (int i = ni; i >= 0; i--) {
			pow2 = (i > 0) ? (2 << (i - 1)) : 1;
			BTM(n - 1, Mtime + pow2, i - 1);
		}
	}

};

int main() {

	Solution s;


	vector<string> res = s.readBinaryWatch(3);

	for (auto str : res) {
		cout << str << ", ";
	}

	system("pause");
	return 0;
}