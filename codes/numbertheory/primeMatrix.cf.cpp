#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pii>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define mic map<int, char>
#define mci map<char, int>
#define mxpqi priority_queue<int>
#define mnpqi priority_queue<int, vi, greater<int>>
#define mxpqpii priority_queue<pii>
#define mnpqpii priority_queue<pii, vpii, greater<pii>>
#define si set<int>
#define pb push_back
#define F first
#define S second
#define B begin()
#define E end() 
#define RB rbegin()
#define RE rend()
#define nl "\n"
#define gcd(a, b) __gcd(a,b)
#define lcm(a,b) ((a / gcd(a, b)) * b)
#define rep(i, a, b) for(int i = a; i < b; i++)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

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

#define dbg(...) printer(#__VA_ARGS__, __VA_ARGS__)

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
const int MAXN = 1000005;
bitset<MAXN> sieve;
void precompute(){
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i*i < MAXN; i++){
        if(sieve[i]){
            for(int j = i*i ; j < MAXN; j+=i){
                sieve[j] = 0;
            }
        }
    }
}

template<typename T>
void _sort(vector<T>& vec, bool rev = false){
    if(rev) { sort(vec.RB, vec.RE); return;}
    sort(vec.B, vec.E); return;
}

template<typename T>
void _input(vector<T>& vec, int a, int b){
    rep(i,a,b){
        cin >> vec[i];
    }
}

int solve(){
    int n, m;
    cin >> n>>m;
    int lastFound = -1;
    vi vec(MAXN);
    for(int i = MAXN-1; i>= 0; i--){
        if(sieve[i] == 1){
            lastFound = i;
        }else{
            if(lastFound > 0){
                vec[i] = abs(lastFound - i);
            }
        }
    }
    vvi mat(n, vi(m, 0));
    int rowMin = LLONG_MAX;
    vi colSum(m, 0);
    rep(i, 0,n){
        int rowSum = 0;
        rep(j, 0, m){
            int x;
            cin>>x;
            rowSum += vec[x]; 
            // cout<<vec[x]<<" ";
            colSum[j] += vec[x];
        }
        // cout<<nl;
        rowMin = min(rowMin, rowSum);
    }
    int colMin = *min_element(colSum.B, colSum.E);
    return min(rowMin, colMin);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    precompute();
    cout<<solve()<<nl;
    return 0;
}