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
    ll gridGame(vvi& grid) {
        ll result = LONG_MAX;
        ll topRow = 0;
        ll bottomRow = 0;
        int n = grid[0].size();
        for(int i = 0; i< n; i++){
            topRow += grid[0][i];
        }

        for(int i = 0; i< n; i++){
            topRow -= grid[0][i];
            result = min(result, max(topRow, bottomRow));
            bottomRow += grid[1][i];
        }

        return result;
    }
};

