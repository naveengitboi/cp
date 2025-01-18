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
    void DFS(int u, vvi& adj, vi& visited){
        visited[u] = 1;
        for(auto& v:adj[u]){
            if(visited[v] == 0){
                DFS(v, adj, visited);
            }
        }

    }
    bool isConnected(int V, vvi& adj) {
        int nonZeroDegree = -1;
        for(int i = 0; i<V; i++){
            if(adj[i].size() != 0){
                nonZeroDegree = i;
                break;
            }
        }

        vi visited(V, 0);
        DFS(nonZeroDegree, adj, visited);
        for(int i = 0; i< V; i++){
            if(visited[b] == false && adj[i].size() != 0){
                return false;
            }
        }

        return true;
    }
    int isEularCircuit(int V, vvi& adj) {
        if(isConnected(V, adj) == false){
            return 0;
            //Not Eulerian Circuit nor Path;
        }
        int oddDegree = 0;
        for(int i = 0; i< V; i++){
            if(adj[i].size()%2 != 0){
                oddDegree++;
            }
        }
        if(odddegree > 2){
            return 0; // none
        }
        if(oddDegree == 2){
            return 1; //EP
        }
        return 2; //EC

    }

};

