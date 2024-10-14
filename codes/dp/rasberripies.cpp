#include <bits/stdc++.h>
#include <climits>
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

int solve(int arr[],int n, int k){
    int prev = INT_MAX;
    int zeros = 0;
    for(int i = 0; i < n;i++){
        int rem = arr[i]%k;
        if(rem == 0){
            if(k != 4) return 0;
            zeros++;
        }
        prev  = min(prev, k - rem);
    }
    if(k == 4){
        if(zeros < 1) return 2;
        else if(zeros ==1) return 1;
        else if(zeros > 1) return 0;
    }
    return prev;
}
/* Main()  function */
int main () {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i =0; i< n;i++){
            cin>>arr[i];
        }
        int ans = solve(arr, n, k);
        cout<< ans<<endl;

    }

    return 0;
}
/* Main() Ends Here */
