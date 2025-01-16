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

//shortest path from the node 1 to node m;
class Solution {
public:
    vi shortestPath(int n, vvi& edges, int m){

        unordered_map<int, vector<pii>> adj;

        for(auto &vect: edges){
            int u = vect[0];
            int v = vect[1];
            int wt = vect[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 1});
        vi result(n+1, INT_MAX);
        vi parent(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;

            for(auto& vect: adj[node]){
                int adjNode = vect[0];
                int wt = vect[1];

                if(wt+dist < result[adjNode]){
                    result[adjNode] = wt+dist;
                    pq.push({wt+dist, adjNode});
                }
            }
        }

        int destiNode = n;
        if(result[destiNode] == INT_MAX){
            return {-1};
        }

        vi path;
        while(parent[destiNode] != destiNode){
            path.push_back(destiNode);
            destiNode = parent[destiNode];
        }
        path.push_back(1);

        reverse(begin(path), end(path));

        return path;

    }
};

