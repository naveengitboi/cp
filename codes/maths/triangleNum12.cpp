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

int getDivisorsCount(int n){
    int total = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            total +=1;
        }
    }
    if(n > 1){
        total*=2;
    }
    return total;
}


int main(){

    int reach = 500;
    int triangleNum = 1;
    int i = 2;
    while(true){
        if(getDivisorsCount(triangleNum) >= reach){
            break;
        }
        triangleNum += i;
        i++;
    }
    cout<<triangleNum<<endl;

    return 0;
}
