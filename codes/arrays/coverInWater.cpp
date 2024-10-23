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



int solve(int n, string& s){
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i<  n; i++){
        if(s[i] == '.'){
            cnt++;
        }
        if(s[i] == '#' || i == n-1){
            if(cnt >= 3){
                return 2;
            }
            ans += cnt;
            cnt = 0;
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        int ans = solve(n, s);
        cout<<ans<<endl;
    }

    return 0;
}


