#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define vvi vector<vector<int>>
#define ull unsigned long long

int solve(string& s){
    int ones = 0;
    int zeros = 0;
    for(char ch:s){
        if(ch == '1'){
            ones++;
        }else{
            zeros++;
        }
    }
    for(char ch: s){
        if(ch == '1' && zeros > 0){
            zeros--;
        }
        else if(ch == '0' && ones>0){
            ones--;
        }
        else{
            if(zeros == 0) return ones;
            else return zeros;
        }
    }
    return 0;
}

/* Main()  function */
int main () {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = solve(s);
        cout<<abs(ans)<<endl;
    }

    return 0;
}
/* Main() Ends Here */
