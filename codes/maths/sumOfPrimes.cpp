
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
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long long range = 2000000;
   long long summation = 0;
   long long n = 2;
   while(n < range){
       if(isPrime(n)){
            summation += n;
       }
       n++;
   }
   cout<<summation<< endl;
    return 0;
}
