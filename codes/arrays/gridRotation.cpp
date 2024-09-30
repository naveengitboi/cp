#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;


void reverseGrid(vvi& mat){
  int n = mat.size();
  for(int j = 0; j < n/2; j++){
    for(int i = 0 ; i <n; i++){
      swap(mat[i][j], mat[i][n-j-1]);
    }
  }
}
vvi rotateGrid(vvi& mat){
  int n = mat.size();
  for(int i = 0; i< n; i++){
    for(int j = 0; j< i; j++){
      swap(mat[i][j] , mat[j][i]);
    }
  }
  
  reverseGrid(mat);
  return mat;

}
