#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <string>
#include <sys/types.h>
#include <unordered_map>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define vs vector<string> 
#define vmp vector<unordered_map<int, int>>
//leetcode 446 hard

int dfs(int r, int c,vvi& mat){
  if(r ==  mat.size()-1) return mat[r][c];
  
  int minSum = INFINITY;
  int curr = mat[r][c];
  
  if(r +1 < mat.size()){
    minSum = min(minSum, curr + dfs(r+1,c, mat));
  }
  if(r +1 < mat.size() && c+1 < mat[0].size()){
    minSum = min(minSum, curr + dfs(r+1,c+1, mat));
  }
  if(r-1 >=0 && c-1 >= 0){
    minSum = min(minSum, curr + dfs(r-1,c-1, mat));
  }


  return minSum;
}
int numberOfArithmetics(vvi& matrix){
  int row = 0;
  int minTotal= INT_MAX;
  for(int col = 0; col < matrix[0].size(); col++){
    minTotal = min(minTotal, dfs(row, col, matrix));
  }
  return minTotal;
}
int main(){
  


  return 0;
}
