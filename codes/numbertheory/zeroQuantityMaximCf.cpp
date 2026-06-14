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
#define x first
#define y second
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



void normalize(pii& p){
    if(p.x < 0){
        p.x *= -1;
        p.y *= -1;
    }else if(p.x == 0 && p.y < 0){
        p.y *= -1;
    }
    int d = __gcd(abs(p.x), abs(p.y));
    p.x /= d;
    p.y /= d;
}


int solve(int t){
    vi a(t), b(t);
    _input(a, 0, t-1);
    _input(b, 0, t-1);
    map<pii, int> mp;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < t;i++){
        if(a[i] == 0){
            if(b[i] == 0){
                cnt++;
            }
        }
        else{
            pii p = make_pair(-b[i], a[i]);
            normalize(p);
            mp[p]++;
            ans = max(ans, mp[p]);
        }
    }
    return cnt + ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    cout<<solve(t)<<endl;
    return 0;
}


