#include <bits/stdc++.h>
#include <cmath>
using namespace std;
class solution {
public:
  void arrangeColors(vector<int> &arr) {
    map<int, int> mpp ;

    for(auto it: arr){
      mpp[it] ++;
    }

    int j =0;
    for(int i =0;i<3; i++){
        while(mpp[i]){
        arr[j] = i;
        j+=1;
        mpp[i]--;
      }
    }

    
  }
};
