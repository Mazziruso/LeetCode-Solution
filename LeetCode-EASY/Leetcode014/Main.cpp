#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) {
            return "";
        }
        string prex = strs[0];
        int len = strs.size();
        int index;
        for(int i=0; i<len-1; i++) {
            index = 0;
            while(index<prex.length() && index<strs[i+1].length() && prex[index]==strs[i+1][index]) {
                index++;
            }
            prex = prex.substr(0,index);
        }
        return prex;
    }
};
