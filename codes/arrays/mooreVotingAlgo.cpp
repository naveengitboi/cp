#include <bits/stdc++.h>
using namespace std;

//occurences > [n/2] times 
//moore voting algorithm
//
int moreThanNBy2(vector<int>& nums){
    int cnt = 1;
    int ans = nums[0];
    int n= nums.size();
    for(int i = 1; i< n; i++){
        if(ans == nums[i]){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt == 0){
            ans = nums[i];
        }
    }
    return ans;
}

//occurences > [n/3] times 
// O(n) TC + O(n) SC
vector<int> approachOne(vector<int>& nums){
    map<int, int> freq;
    vector<int> ans;
    for(int i = 0; i< nums.size(); i++){
        freq[nums[i]]++;
    }
    for(auto p: freq){
        if(p.second > nums.size()/3){
            ans.push_back(p.first) ;
        }
    }
    return ans;
}
