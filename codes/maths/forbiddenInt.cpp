#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>


void solve(int n, int k, int x){
    if(k == 1 && x == 1){
        cout<<"NO"<<endl;
        return;
    }
    mii mp;
    int prev = 0;
    for(int i = 0; i< k;i++){
        if(i != x){
            mp[i]++;
            mp[i+prev]++;
            prev = i;
        }
    }
    vi vect;
    for(int i = k; i>= 1; i--){
        if(i != x){
            int q = n%mp[i];
            if(mp.find(q) != mp.end()){
                cout<<"NO"<<endl;
            }else{
                n -= mp[i]*q;
            }
        }
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k, x;
        cin>>n>>k>>x;
        solve(n, k, x);
    }

    return 0;
}


