//fisher yets algorithm
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>


class Solution {
private:
    vi original;
    int n;
public:
    Solution(vi& nums){
        original = nums;
        n = nums.size();
    } 
    vi reset(){
        return original;
    }
    vi shuffle(){
        vi shuffled = original;
        int pointer = n;
        for(int i = n-1; i > 0; i--){
            int j = rand() % pointer;
            swap(shuffled[i], shuffled[j]);
            pointer--;
        }
        return shuffled;
    }
};

