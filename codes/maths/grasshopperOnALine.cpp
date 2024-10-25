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





int main() {
    int t;
    cin>>t;
    while(t--){
        int x, k;
        cin>>x>>k;
        if(x%k == 0){
            cout<<2<<endl;
            cout<< x-1<<" "<<1<<endl;
        }else{
            cout<<1<<endl;
            cout<< x<<endl;
        }
    }

    return 0;
}


