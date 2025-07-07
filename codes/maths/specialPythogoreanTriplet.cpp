
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

bool isPythoTriplte(int a, int b, int c){
    return (c*c == (a*a + b*b));
}


int main(){
    int a = 0;
    int b = 0;
    for(a; a < 500; a++){
        bool found =false;
        for(b = a; b < 500 ; b++){
            if(isPythoTriplte(a, b, 1000-a-b)){
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
    long long prod = a*b*(1000-a-b);
    cout<<prod<<endl;
    return 0;
}
