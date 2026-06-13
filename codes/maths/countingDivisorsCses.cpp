#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define mod 1000000007
#define int long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>
#define pb push_back
#define f first
#define s second
#define b begin
#define e end
#define rb rbegin
#define re rend
#define gcd(a, b) __gcd(a,b)
#define lcm(a,b) (a/(gcd(a, b)*b))
#define bug(x) cout<<#x<<" "<<x<<endl

// functions
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
bool isPrime(int n){
    if(n < 2) return false;
    for(int i =2; i <= round(sqrt(n)); i++){
        if(n%i == 0) return false;
    }
    return true;
}
void _sort(vi& a,bool rev=false){
    if(rev){sort(a.rb(), a.re()); return;}
    sort(a.b(), a.e()); return;
}
void _input(vi& a, int s, int  e){
    for(int i = s; i <= e; i++){
        cin>>a[i];
    }
}

void sieve(vi& a){
    a[0] = 0, a[1] = 0;
    for(int i = 2; i < a.size() ;i++){
        if(a[i]){
            for(int j = i*i; j<a.size();j+=i){
                a[j] = 0;
            }
        }
    }
}




int solve(map<int, mii>& dp, vi& vec){
    int n;
    cin>>n;
    int ans = 1;
    mii curr;
    bool found = false;
    int x = n;
    while(n > 1){
        if(dp.find(n) != dp.end()){
            found = true;
            break;
        }
        int i = 2;
        if(vec[n]){
            curr[n]++;
            break;
        }
        for(;i*i <= n;i++){
            if(n%i == 0){
                n /= i;
                curr[i]++;
                break;
            }
        }
    }
    //calcuate dp
    if(found){
        for(auto v: dp[n]){
            curr[v.first] += v.second;
        }
    }
    for(auto c: curr){
        ans = ans*(c.second + 1);
    }
    dp[x] = curr;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    map<int, mii> dp;
    vi vec(1e6+2, 1);
    sieve(vec);
    while(t--){
        cout<<solve(dp, vec)<<endl;
    }
    return 0;
}


