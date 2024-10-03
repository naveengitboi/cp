#include <bits/stdc++.h>
using namespace std;



//approach one
int trappingRainWater(vector<int>& heights){
    int n = heights.size();
    vector<int> prefixMax(n, heights[0]);
    vector<int> suffixMax(n, heights[n-1]);
    
    for(int i = 1; i< n; i++){
            prefixMax[i] = max(prefixMax[i-1], heights[i]);
    }

    for(int i = n-2; i>=0; i--){
        suffixMax[i] = max(suffixMax[i+1], heights[i]);
    }

    int ans = 0;
    for(int i = 0; i< n; i++){
        int x = min(prefixMax[i], suffixMax[i]) - heights[i];
        if(x >=0){
            ans += x;
        }
    }
    return ans;

}


//approach two optimal

int trappingMethodTwo(vector<int> heights){
    int n = heights.size();
    int i = 0;
    int j = n-1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    while(i <= j){
        if(leftMax <= rightMax){
            int x = leftMax - heights[i];
            if(x >= 0){
                ans+= x;
            }else{
                leftMax = heights[i];
            }
            i++;
        }else{
            int x = rightMax - heights[j];
            if(x >= 0){
                ans+= x;
            }else{
                rightMax = heights[j];
            }
            j--;
        }
    }

    return ans;
}



