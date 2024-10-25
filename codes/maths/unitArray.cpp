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


int solve(int n){
    mii mp;
    mp[1] = 0;
    mp[-1] = 0;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    int times = 0;
    while((mp[1]*1 + (-1)*mp[-1]) < 0){
        mp[-1]--;
        mp[1]++;
        times++;
    }
    if(mp[-1]%2 != 0){
        times++;
    }
    return times;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = solve(n);
        cout<<ans<<endl;
    }

    return 0;
}


