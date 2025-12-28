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






bool solve(){
    string s,t;
    cin>>s>>t;
    unordered_map<char, vi> mp;
    unordered_map<char, int> mpt;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]].push_back(i);
    }

    for(int i = 0; i < t.size(); i++){
        mpt[t[i]]++;
    }

    string st(s.size(), ' ');

    for(auto p: mpt){
        vi vec;
        if(mp.find(p.f) != mp.end()){
            vec = mp[p.f];
        }else{
            return false;
        }
        int n = vec.size();
        int x = p.s;
        if(x > n) return false;
        while(x--){
            st[vec[n-1]] = p.f;
            n--;
        }
    }
    string ans = "";
    for(auto ch : st){
        if(ch != ' ') ans += ch;
    }
    return ans == t;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        bool y = solve();
        if(y){
            yes();
        }else{
            no();
        }
    }
    return 0;
}


