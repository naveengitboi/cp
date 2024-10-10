
#include <bits/stdc++.h>
using namespace std;
// @leet start 79 word search
#define vvc vector<vector<char>> 
#define vvi vector<vector<int>>
class Solution {
public:
    int m, n, l;
    bool dfs(vvc& board, string& word, int i , int j, int k , vvi& visited){
        if(i <0 || i>= m || j >= n || j < 0) return false;
        if(k >= l-1 && word[k] == board[i][j] && !visited[i][j]) return true;
        if(!visited[i][j] && word[k] == board[i][j]){
            visited[i][j] = 1;
            bool right = dfs(board, word, i, j+1, k+1, visited);
            bool down = dfs(board, word, i+1, j, k+1, visited);
            bool left = dfs(board, word, i, j-1, k+1, visited);
            bool up = dfs(board, word, i-1, j, k+1, visited);
            visited[i][j] =0;
            return right || down || left || up;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        l= word.length();
        m = board.size();
        n = board[0].size();
        vvi visited(m, vector<int>(n, 0));
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                    bool ans = dfs(board, word, i, j, 0, visited);
                    if(ans) return ans;
            }
        }
        return false;
    }
};
