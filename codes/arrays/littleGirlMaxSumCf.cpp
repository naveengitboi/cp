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
const int N = 2e5+1;
int diff[N];
int pref[N];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    int x = q;
    vi vec(N, 0);
    _input(vec, 1, n);
    vvi ques;
    while(x--){
        int l,r;
        cin>>l>>r;
        diff[l]++;
        diff[r+1]--;
        ques.push_back({l,r});
    }
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
        pq.push(make_pair(diff[i], i));
    }
    auto comp = [&](int a, int b){
        return b < a;
    };
    sort(vec.begin(), vec.end(), comp);
    int idx = 0;
    while(!pq.empty()){
        pii q = pq.top();
        pq.pop();
        pref[q.s] = vec[idx++];
    }
    for(int i = 1; i <= vec[0] + 1; i++){
        pref[i] += pref[i-1];
    }
    int ans = 0;
    for(auto &q: ques){
        int l  = q[0];
        int r  = q[1];
        ans += pref[r]-pref[l-1];
    }
    cout<<ans<<endl;
    return 0;
}


