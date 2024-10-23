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


bool solve(int n, int k, vi& nums){
    for(auto num : nums){
        if(num == k) return true;
    }
    return false;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n >>k;
        vi vect(n);
        for(int i = 0; i< n; i++){
            cin>>vect[i];
        }
        bool ans = solve(n, k , vect);
        if(ans){
            cout<<"YES" <<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}


