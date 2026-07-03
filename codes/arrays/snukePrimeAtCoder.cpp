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
    int n , k;
    cin>>n>>k;
    vvi data;
    si st;
    while(n--){
        int a, b, c;
        cin>>a>>b>>c;
        st.insert(a);
        st.insert(b + 1);
        data.push_back({a,b,c});
    }

    int idx = 0;
    mii mp;
    for(auto &it: st){
        mp[it] = idx;
        idx++;
    }

    vi vec(idx+1, 0);
    for(int i = 0; i < data.size();i++){
        int a = data[i][0];
        int b = data[i][1];
        int c = data[i][2];
        vec[mp[a]] += c;
        vec[mp[b+1]] -= c;
    }
    for(int i = 1; i <= idx; i++){
        vec[i] += vec[i-1];
    }
    vi a(st.begin(), st.end());
    int ans = 0LL;
    for(int i = 1; i < a.size(); i++){
        int span = a[i] - a[i-1];
        ans += 1LL*span*min(vec[i-1], k);
    }
    cout<<ans<<endl;

    return 0;
}


