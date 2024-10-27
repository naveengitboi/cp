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

void print(vi& vect){
    for(int i =  0; i< vect.size(); i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}
void solve(int n, int k, int x){
    if(k == 1 && x == 1){
        cout<<"NO"<<endl;
        return;
    }
    int sum = n; 
    vi vect;
    while(true){
        bool useFul = false;
        for(int i = k; i>= 1 ; i--){
            if(i != x && sum - i >= 0){
                sum-=i;
                vect.push_back(i);
                useFul = true;
            }
            if(sum == 0){
                break;
            }
        }
        if(!useFul){
            break;
        }
    }
    if(sum != 0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int p = vect.size();
    cout<<p<<endl;
    print(vect);

}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k, x;
        cin>>n>>k>>x;
        solve(n, k, x);
    }

    return 0;
}


