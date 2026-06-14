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

const int mad = 998244353;

int binPower(int a, int b){
    int res = 1;
    while(b){
        if(b&1){
            res = (res*a)%mad;
        }
        a = (a*a)%mad;
        b>>= 1;
    }
    return res;
}




int solve(int t){
    mii  mp;
    for(int i = 0; i < t;i++){
        int x;
        cin>>x;
        mp[x]++;
        if(i == 0 && x != 0) return 0;
    }
    if(mp[0] != 1) return 0;
    int ans = 1;
    for(int l = 1; l<=t; l++){
        int x = mp[l];
        if(x == 0) continue;
        int parent = mp[l-1];
        if(parent == 0){
            return 0;
        }
        ans = (ans*binPower(parent, x)%mad);
        ans %= mad;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    cout<<solve(t)<<endl;
    return 0;
}


