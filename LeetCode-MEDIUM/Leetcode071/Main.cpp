#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> dirs;
    string simplifyPath(string path) {
        int n = path.size();
        int index = 0;
        int start;
        string str;
        while(index<n) {
            while(index<n && path[index]=='/') {
                index++;
            }
            start = index;
            while(index<n && path[index]!='/') {
                index++;
            }
            //
            if(start == index) {
                continue;
            }
            str = path.substr(start, index-start);
            if(str==".") {
                continue;
            } else if(str==".."){
                if(!dirs.empty()) {
                    dirs.pop_back();
                }
            } else {
                dirs.push_back(str);
            }
        }

        string res = "";
        if(dirs.empty()) {
            return "/";
        } else {
            for(string s : dirs) {
                res += "/";
                res += s;
            }
            return res;
        }
    }
};

int main() {

    string path = "/a/./b/../../c/";

    cout << Solution().simplifyPath(path) << endl;

    return 0;
}