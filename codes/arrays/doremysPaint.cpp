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


bool solve(int n, vi& nums){
    mii mpp;
    if(n<=2){
        return true;
    }
    for(auto num: nums){
        mpp[num]++;
    }
    if(mpp.size()  <= 2){
        if(mpp.size() == 1) return true;
        int prev = -1;
        for(auto p: mpp){
            if(prev == -1){
                prev = p.second;
            }
            else{
                prev = abs(prev  - p.second);
            }
        }
        if(prev <= 1) return true;
    }
    return false;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi vect(n);
        for(int i =0;i< n; i++){
            cin>>vect[i];
        }
        bool ans = solve(n, vect);
        if(ans){
            cout<<"YES" <<endl;
        }else{
            cout<<"NO" <<endl;
        }
        
    }

    return 0;
}


