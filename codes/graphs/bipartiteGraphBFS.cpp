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
    bool BFS(vii& adj, int u, vi& color, int currColor){
        queue<int> q;
        q.push(u);
        color[u] = currColor;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto & v: adj[node]){
                if(color[v] == color[node]) return false;
                if(color[v] == -1){
                    color[v] = 1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
  }
    int checkBipartiteBFS(vii adj, int V) {
        vi color(V, -1);

        for(int i = 0; i< V; i++){
            if(color[i] == -1) 
                if(!BFS(adj, i, color, 1)) return false;
        }
        return true;
    }
};

