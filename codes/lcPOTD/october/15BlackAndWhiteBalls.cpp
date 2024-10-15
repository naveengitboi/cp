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


ll getMinSwaps(string s){
    ll bballs = 0;
    ll ans =  0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            ans += bballs;
        }else {
        bballs++;
        }
    }
    return ans;
}


int main() {
    return 0;
}


