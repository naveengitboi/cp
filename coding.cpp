#include <bits/stdc++.h>
#include <climits>
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


int solve(int arr[], int n , int k){
    int cnt =0;
    int prev = k-1;
    for(int i = 0; i< n; i++){
        int rem = arr[i]%k;
        if(arr[i]%2 == 0){
            cnt++;
        } 
        if(rem == 0){
            return 0;
        }
        prev = min(prev, k-rem);
    }
    if(k == 4){
        int val = INT_MAX;
        if(cnt == 0){
            val = 2;
        }else if(cnt == 1) val=1;
        else if(cnt > 1) val=0;
        return min(val, prev);
    }
    return prev;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i = 0; i<n ; i++){
            cin>>arr[i];
        }
        int ans = solve(arr, n, k);
        cout<<ans<<endl;
    }
    return 0;
}


