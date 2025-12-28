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
void _sort(vi& a, bool rev=false){
    if(rev){
        sort(a.rb(), a.re());
    }
    sort(a.b(), a.e());
}
void _input(vi& a, int s, int  e){
    for(int i = s; i <= e; i++){
        cin>>a[i];
    }
}






void solve(){
    int n;
    cin>>n;
    vi a(n+1, 0);
    _input(a, 1, n);
    int i = 1;
    while(a[i] == 0  && i <= n){
        i++;
    }
    while(i <= n && a[n] == 0){
        n--;
    }
    if(i > n){
        cout<<0<<endl;
        return;
    }
    int cnt = 1;
    while(i <= n){
        if(a[i] == 0){
            cnt = 2;
            break;
        }
        i++;
    }
    cout<<cnt<<endl;
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


