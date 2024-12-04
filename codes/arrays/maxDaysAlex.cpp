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


int solve( int n, vector<int> arr){
    int ans = 0;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i< n ; i ++){
        sum += arr[i];
        if(sum >= 0){
            cnt++;
            ans = max(ans, cnt);
        }else{
            sum = 0;
            cnt = 0;
        }
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0; i<n; i++){
        cin>>v[i];
    }
    int ans = solve(n, v);
    cout<<ans<<endl;
    return 0;
}


