#include <bits/stdc++.h>
#include <cmath>
using namespace std;



int largestSubarraySum(vector<int>& arr) {
  int total =0 ;
  int maxi = -INFINITY;
  for(int i = 0;i < arr.size(); i++){
    total += arr[i];
    maxi = max(maxi, total);
    if(total  <0 ){
      total = 0;
    }
  }

  return maxi;
        
}



  int maxPairSum(vector<int>& arr, int n) {

  int maxi = arr[0] + arr[1];
  for(int  i =1; i<arr.size()-1; i++){
    maxi = max(maxi, arr[i] + arr[i+1]);
  }


  return maxi;
  
}

//brute force buy and sell stock
int buyAndSell(vector<int> arr){

  int maxi = 0;

  for(int i =0; i<arr.size(); i++){
    int buy = arr[i];
    for(int j = i+1; j<arr.size(); j++){
      maxi = max(maxi, arr[j] - buy);
    }
  }
return maxi;
        
}


//optimal or best approach
//

int maximizeShareProfit(vector<int> arr){

  int minimum = arr[0];
  int profit  = 0;
  int maxiProfit = 0;
  
  for(int i =0 ; i< arr.size(); i++){
    profit = arr[i] - minimum;
    maxiProfit = max(maxiProfit, profit);
    minimum = min(minimum, arr[i]);
  }


  return maxiProfit ;

}
