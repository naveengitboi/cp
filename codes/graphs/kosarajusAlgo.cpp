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
    void dfs(int u, vvi& adj,vi& visited, stack<int>& topoStack){
        visited[u] = 1;
        for(auto& v: adj[u]){
            if(visited[v] == 0){
                dfs(v, adj, visited, topoStack);
            }
        }
        topoStack.push(u);
    }
    void getConnected(int u,vvi& adjReversed, vi& newVisited){
        newVisited[u] = 1;
        for(auto& v: adjReversed[u]){
            if(newVisited[v] == 0){
                getConnected(v, adjReversed, newVisited);
            }
        }
    }
    int kosaraju(int V, vvi adj) {
        vi visited(V, 0);
        stack<int> topoStack;

        for(int i = 0; i< V; i++){

            if(visited[i] == 0){
                dfs(i, adj, visited, topoStack);
            }
        }

        vvi adjReversed(V);

        //directed graph reversed;
        for(int u = 0; u<V; u++){
            for(auto &v:adj[u]){
                adjReversed[v].push_back(u);
            }
        }

        vi newVisited(V, 0);

        int scc = 0;
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(newVisited[u] == 0){
                getConnected(u, adjReversed, newVisited);
                scc++;
            }
        
        }
        

        return scc;
        
    }
};

