#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int> 



ll maxScore(vi& a, vi& b){
    ll ans;
    int n = b.size();
    for(int i = 0;i+4<n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l<n ; l++){
                    ll v =b[k]*a[2]+ b[j]*a[1] + b[i]*a[0] + b[l]*a[4];
                    ans = max(ans, v);
                }
            }
        }
    }
    return ans;
}
