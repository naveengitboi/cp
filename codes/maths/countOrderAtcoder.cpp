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
int getFact(int x){
    int fct = 1;
    for(int i = 1; i <= x;i++){
        fct *= i;
    }
    return fct;
}




int solvePerm(int x, int n, vi visited, int pos){
    int cnt = 0;
    for(int i = 1; i < x;i++){
        if(visited[i] == 0) cnt++;
    }
    // cout<<x<<" Cnt "<<pos<<" "<<cnt<<endl;
    return cnt*getFact(n - pos);
}

int solve(int n){
    vi visited(n+1, 0);
    int xPos = 1;
    for(int i = 1; i <= n;i++){
        int x;
        cin>>x;
        xPos += solvePerm(x, n, visited, i);
        // cout<<xPos<<endl;
        visited[x] = 1;
    }
    return xPos;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int xPos = solve(n);
    int yPos = solve(n);
    // cout<<xPos<<" "<<yPos<<endl;
    cout<<abs(xPos - yPos)<<endl;
    return 0;
}


