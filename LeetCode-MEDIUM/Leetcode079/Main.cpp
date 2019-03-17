#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n;
    int m;
    vector<int> dx;
    vector<int> dy;
    vector<vector<bool>> vis;
    string str;
    bool DFS(vector<vector<char>> &board, int index, int x, int y) {
        if(index==str.size()-1) {
            return true;
        }
        int nx;
        int ny;
        bool flag = false;
        for(int i=0; i<4; i++) {
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]) {
                //if flag is true then stop and break out
                if(flag) {
                    break;
                }
                if(board[nx][ny]==str[index+1]) {
                    vis[nx][ny] = true;
                    flag = DFS(board,index+1,nx,ny) ? true : flag;
                    vis[nx][ny] = false;
                }
            }
        }
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->n = board.size();
        if(n==0) {
            return false;
        }
        if(word.empty()) {
            return true;
        }
        this->m = board[0].size();
        this->str = word;
        dx = {-1,0,1,0};
        dy = {0,1,0,-1};
        vis.resize(n,vector<bool>(m,false));

        bool flag = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                //early stop
                if(flag) {
                    return true;
                }
                if(board[i][j]==str[0]) {
                    vis[i][j] = true;
                    flag = DFS(board, 0, i, j) ? true : flag;
                    vis[i][j] = false;
                }
            }
        }
        return flag;
    }
};

int main() {

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    cout << (Solution().exist(board, "ABCB") ? "true" : "false") << endl;

    return 0;
}