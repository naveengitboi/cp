#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;


vector<int> spiralMatrix(vvi& mat){
  vector<int> ans;
  int m = mat.size();
  int n = mat[0].size();
  int top = 0, bottom = m-1;
  int left = 0, right = n-1;
  while(top <= bottom && left <= right){
    //left to right
    for(int j = left ; j<= right; j++){
      ans.push_back(mat[top][j]);
    }
    top++;
    
    //top to bottom
    for(int j = top; j <= bottom; j++){
      ans.push_back(mat[right][j]);
    }
    right--;
    if(top <= bottom){
      for(int j = right; j >=left; j--){
        ans.push_back(mat[bottom][j]);
      }
    }
    bottom--;
    if(left <= right){

      for(int j = bottom; j >=top; j--){
        ans.push_back(mat[left][j]);
      }
    }
    left++;
  }
  return ans;
}
