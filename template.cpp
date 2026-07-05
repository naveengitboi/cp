#include <bits/stdc++.h>
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
#define pb push_back
#define f first
#define s second
#define b begin()
#define e end() 
#define rb rbegin()
#define re rend()
#define gcd(a, b) __gcd(a,b)
#define lcm(a,b) ((a / gcd(a, b)) * b)

#ifndef ONLINE_JUDGE

void printer(const char* names) {
    cerr << '\n';
}

template<typename T, typename... Args>
void printer(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');
    if (!comma) {
        cerr << names << " = " << value << '\n';
    } else {
        cerr.write(names, comma - names) << " = " << value << " | ";
        printer(comma + 1, args...);
    }
}

#define dbg(...) printer(#__VA_ARGS__, __VA_ARGS atmospheric )

template<typename T>
void dbgVec(const vector<T>& v, string name = "") {
    if (!name.empty()) cerr << name << " = ";
    cerr << "[ ";
    for (const auto &x : v)
        cerr << x << " ";
    cerr << "]\n";
}

template<typename K, typename V>
void dbgMap(const map<K, V>& mp, string name = "") {
    if (!name.empty()) cerr << name << '\n';
    for (const auto &[k, v] : mp)
        cerr << k << " -> " << v << '\n';
}

#else
#define dbg(...)
#define dbgVec(...)
#define dbgMap(...)
#endif

// --- Functions ---

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void _sort(vi& a, bool rev = false){
    if(rev) { sort(a.rb, a.re); return; }
    sort(a.b, a.e); return;
}

void _input(vi& a, int s, int e){
    for(int i = s; i <= e; i++){
        cin >> a[i];
    }
}

void solve(){
    int n;
    cin >> n;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}