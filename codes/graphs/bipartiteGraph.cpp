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
    bool DFS(vii& adj, int u, vi& color, int currColor){
        color[u] = currColor;

        for(auto &v: adj[u]){
            if(color[v] == color[currColor]){
                return false;
            }
            if(color[v] == -1){
                int nextColor = 1- currColor;
                if(!DFS(adj, v, color, nextColor)) return false;
            }
        }
        return true;
    }
    bool bipartiteGraph(int V, vii adj) {
        vi color(V, -1);

        for(int i = 0; i< V; i++){
            if(!DFS(adj, i, color, 1)) return false;
        }
        return true;
    }

};

