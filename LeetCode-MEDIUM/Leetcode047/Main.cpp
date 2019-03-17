#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution_46 {
public:
    vector<int> num;
    vector<bool> vis;
    vector<int> comb;
    vector<vector<int>> combs;

    void DFS(int index) {
        if(comb.size()+1 == num.size()) {
            comb.push_back(num[index]);
            combs.push_back(comb);
            comb.pop_back();
            return;
        }

        comb.push_back(num[index]);
        for(int i=0; i<num.size(); i++) {
            if(!vis[i]) {
                vis[i] = true;
                DFS(i);
                vis[i] = false;
            }
        }
        comb.pop_back();
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) {
            return combs;
        }

        this->num = nums;
        sort(this->num.begin(), this->num.end());
        vis.resize(this->num.size(), false);

        for(int i=0; i<this->num.size(); i++) {
            vis[i] = true;
            DFS(i);
            vis[i] = false;
        }

        return combs;
    }
};

class Solution_47 {
public:
    int len;
    vector<int> num;
    vector<bool> vis;
    vector<int> comb;
    vector<vector<int>> combs;

    void DFS(int index) {
        if(len == this->comb.size()+1) {
            comb.push_back(num[index]);
            combs.push_back(comb);
            comb.pop_back();
            return;
        }

        comb.push_back(num[index]);
        for(int i=0; i<len; i++) {
            if(!vis[i]) {
                vis[i] = true;
                DFS(i);
                vis[i] = false;
                while(i<len-1 && num[i]==num[i+1]) {
                    i++;
                }
            }
        }
        comb.pop_back();
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        this->len = nums.size();

        if(len == 0) {
            return combs;
        }

        this->num = nums;
        sort(this->num.begin(), this->num.end());
        vis.resize(len, false);

        for(int i=0; i<len; i++) {
            vis[i] = true;
            DFS(i);
            vis[i] = false;
            while(i<len-1 && this->num[i]==this->num[i+1]) {
                i++;
            }
        }

        return combs;
    }
};


int main() {
    Solution_47 s;
    vector<int> nums({1,1,2,2});
    vector<vector<int>> res = s.permuteUnique(nums);

    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}