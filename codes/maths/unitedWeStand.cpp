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

void printVect(vi& vect){
    for(int i = 0; i< vect.size(); i++){
        cout<<vect[i]<< " ";
    }
    cout<<endl;
}

void solve(int n, vi& a, int mx){
    vi b;
    vi c;
    for(int i = 0;i < n;i++){
        if(a[i] == mx){
            c.push_back(a[i]);
        }else{
            b.push_back(a[i]);
        }
    }
    if(b.size() == 0 or c.size() == 0){
        cout<<-1<<endl;
    }else{
        cout<<b.size() << " " << c.size()<<endl;
        printVect(b);
        printVect(c);
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi vect(n);
        int mx = 0;
        for(int i = 0; i< n;i++){
            cin>>vect[i];
            mx = max(mx, vect[i]);
        }
        solve(n, vect, mx);
    }

    return 0;
}


