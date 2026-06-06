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






string solve(){
    int n, k;
    cin>>n>>k;
    vi primes(n+1, true);
    primes[0] = false;
    primes[1] = false;
    int tPrimes = 0;
    for(int i = 2; i<= n; i++){
        if(primes[i]){
            tPrimes++;
            int j = i;
            while(j+i <= n){
                primes[j+i] = false;
                j+=i;
            }
        }
    }
    if(tPrimes < k){
        return "NO";
    }
    for(int i = 0; i < n; i++){
        if(primes[i]){
            int j = i+1;
            while(!primes[j]){
                j++;
            }
            if((i+j+1)<=n && isPrime(i + j + 1)){
                k--;
            }
        }
        if(k == 0) return "YES";
    }
    return "NO";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve()<<endl;
    return 0;
}


