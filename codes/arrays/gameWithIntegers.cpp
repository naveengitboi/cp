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


bool solve(int n){
    if((n+1)%3 == 0 || (n-1)%3 ==0){
        return true;
    }
    return false;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool won = solve(n);
        if(won){
            cout<<"First"<<endl;
        }else{
            cout<<"Second"<<endl;
        }

    }

    return 0;
}


