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



int getVal(vi& a, int idx){
    int t = 0;
    vi vec;
    int n = a.size();
    for(int i= 0; i < n; i++){
        if(i == idx){
            continue;
        }
        vec.push_back(a[i]);
    }
    for(int i= 0; i < vec.size() - 1; i++){
        int curr = abs(vec[i] -vec[i+1]);
        t += curr;
    }
    return t;

}


void solve(){
    int n;
    cin>>n;
    vi a(n);
    _input(a, 0, n-1);
    int ans = LONG_MAX;
    int t = 0;
    for(int i = 0; i < n-1; i++){
        t += abs(a[i] - a[i+1]);
    }
    ans = min(ans, t - abs(a[0] - a[1]));
    ans = min(ans, t - abs(a[n-1] - a[n-2]));
    for(int i = 1; i < n-1; ++i){
        ans = min(ans, t - abs(a[i] - a[i-1]) - abs(a[i] - a[i+1]) + abs(a[i-1] - a[i+1]));
    }
    cout<<ans<<endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


