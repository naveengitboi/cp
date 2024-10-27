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
    int cnt = 0;
    int i = 0, j = n-1;
    while(i < j){
        if(s[i] != s[j]){
            cnt+=2;
            i++;
            j--;
        }else{
            break;
        }
    }
    return n - cnt;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = solve(n,s);
        cout<<ans<<endl;
    }

    return 0;
}


