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
        int n;
        cin>>n;
        int cnt = 0;
        for(int i = 0; i< n; i++){
            int temp;
            cin>>temp;
            if((temp&1)){
                cnt++;
            }
        }
        if(cnt&1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }

    return 0;
}


