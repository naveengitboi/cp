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


bool isPrime(int n){
    for(int i = 2; i*i <= n ; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int cnt = 1;
    int num =  2;
    while(cnt < 10001){
        num++;
        if(isPrime(num)){
            cnt++;
        }
    }
    cout<<num<<endl;
    return 0;
}


