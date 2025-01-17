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


class Solution {
public:
    void floyedWarshell(int n, vvi &graphMatrix) {
        for(int via = 0; via < n; via++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j<n; j++){
                    graphMatrix = min(graphMatrix[i][j] , graphMatrix[i][via] + graphMatrix[via][j]);
                }
            }
        }
        //no need to return, we are changing the graph in place
    }
};

