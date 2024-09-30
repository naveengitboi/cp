#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

int checkFor(int r, int c, vvi &b, int k) {

  int m = b.size();
  int n = b[0].size();
  int cnt = 0;
  for(int i = max(0, r-1); i+1< m; i++){
    for(int j = max(0, c-1); j+1<n; j++){
      if(i != r && j != c){
        if(b[i][j] == k) cnt++;
      }
    }
  }
  return cnt;
}
void nextGenerationGrid(vvi &board) {
  int m = board.size();
  int n = board[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int k = checkFor(i,j, board, 1);
      if(board[i][j] == 0){
        if(k == 3) board[i][j] = 1;
      }else{
        //under population
        if(k < 2) board[i][j] = 0;
        else if(k == 2 or k == 3) board[i][j] = 1;
        else{
          //over population
          board[i][j] = 0;
        }
      }
    }
  }
}
