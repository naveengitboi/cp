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
        int n, m;
        cin>>n>>m;
        string x;
        cin>>x;
        string s;
        cin>>s;
        bool found = false;
        for(int i = 0; i<= 5; i++){
            if(x.find(s) != string::npos){
                cout<<i<<endl;
                found = true;
                break;
            }
            x.append(x);
        }
        if(!found) cout<<-1<<endl;
    }
    return 0;
}


