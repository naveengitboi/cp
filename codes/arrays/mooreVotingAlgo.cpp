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


//approach 2 


vector<int> approachTwo(vector<int>& nums){
    int leaderOne = INT_MIN;
    int freq1 = 0;
    int freq2 = 0;
    int leaderTwo = INT_MIN;
    int n = nums.size();
    for(int i = 0; i< n;i++){
        if(freq1 == 0){
            leaderOne = nums[i];
            freq1++;
        }else if(nums[i] != leaderOne && freq2 == 0){
            leaderTwo = nums[i];
            freq2++;
        }
        else if(nums[i] == leaderOne){
            freq1++;
        }else if(nums[i] == leaderTwo){
            freq2++;
        }
        else{
            freq1--;
            freq2--;
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i<n; i++){
        if(leaderOne == nums[i]){
            cnt1++;
        }
        if(leaderTwo == nums[i]){
            cnt2++;
        }
    }
    vector<int> ans;
    if(cnt1 > n/3){
        ans.push_back(leaderOne);
    }
    if(cnt2 > n/3){
        ans.push_back(leaderTwo);
    }
    return ans;
}
