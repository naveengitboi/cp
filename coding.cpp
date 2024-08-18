#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define vvi vector<vector<int>>

/* Main()  function */


void solve(vvi& arr,vvi& visited, int i, int j, int row, int col){
  visited[i][j] = 1;
  arr[i][j]= 0;
  if(row == i && j+1< arr[0].size()){
     solve(arr, visited, i, j+1, row, col);
  }
  if(row == i && j-1>=0){
     solve(arr, visited, i, j-1, row, col);
  }
  if(col == j && i-1>=0){
     solve(arr, visited, i-1, j, row, col);
  }
  if(col == j && i+1>=0){
     solve(arr, visited, i+1, j, row, col);
  }
}

int main() {

  int n;
  int m;
  cin >> m >> n;
  vvi arr;
  
  vvi visited(m, vector<int>(n, 0));
  for(int i = 0; i < m; i++){
    
    vi temp;
    for(int j = 0; j< n; j++){
      int a;
      cin>>a;
      temp.push_back(a);
      
    }
    arr.push_back(temp);
  }


  for(int i = 0; i<m; i++){
    for(int j =0; j< n; j++){
      if(!visited[i][j] && !arr[i][j]){
        solve(arr, visited, i, j, i,j);
      }
    }
  }

  for(int i = 0; i<m; i++){
    for(int j =0; j< n; j++){
      cout<< arr[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}
/* Main() Ends Here */
