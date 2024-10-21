#include <bits/stdc++.h>
#include <climits>
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



int solve(vi& nums, int n, int k){
    int ans = INT_MIN;
    int prev = 0;
    for(int i =0; i< n; i++){
        int dist = (nums[i] - prev);
        ans = max(ans, dist);
        prev = nums[i];
    }
    if(nums[n-1] != k){
        ans = max(ans, 2*(k - nums[n-1]));
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n >> k;
        vi nums(n);
        for(int i = 0; i< n; i++){
            cin>> nums[i];
        }
        int ans = solve(nums, n, k);
            cout<<ans<<endl;
    }

    return 0;
}


