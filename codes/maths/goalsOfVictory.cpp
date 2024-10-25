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
    int sum = 0;
    for(int i = 0; i< n-1; i++){
        int temp;
        cin>>temp;
        sum += temp;
    }
    return -sum;
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


