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






void solve(){
    int n;
    cin>>n;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n , q;
    cin>>n>>q;
    vvi forest(n+1, vi(n+1, 0));
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= n;j++){
            char c;
            cin>>c;
            if(c == '*') forest[i][j] = 1;
            forest[i][j] += forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1];
        }
    }

    while(q--){
        int r1, c1, r2, c2; 
        cin>>r1>>c1>>r2>>c2;
        int ans = forest[r2][c2] - forest[r2][c1-1] - forest[r1-1][c2] + forest[r1-1][c1-1];
        cout<<ans<<endl;
    }

    return 0;
}


