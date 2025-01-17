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
    vi bellmanFordAlgo(vvi &edges, int source, int n) {
        vi result(n, INT_MAX);
        result[source] = 0;

        for(int i = 0 ; i<= n-1; i++){
            for(auto& edge:edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(result[u] != INT_MAX && result[u] + wt < result[v]){
                    result[v] = result[u] + wt;
                }
            }
        }
        ///if negative cycle is there;
        
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(result[u] != INT_MAX && result[u] + wt < result[v]){
                return {-1};
            }
        }

        //if no negative cycle;
        return result;
    }
};


