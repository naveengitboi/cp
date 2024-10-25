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



bool solve(int x, int y, int isOdd){
    if(x == y){
        if(isOdd){
            return true;
        }
        return false;
    }
    return x>y;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        bool ans = solve(a, b, c&1);
        if(ans){
            cout<<"First"<<endl;
        }else{
            cout<<"Second"<<endl;
        }
    }

    return 0;
}


