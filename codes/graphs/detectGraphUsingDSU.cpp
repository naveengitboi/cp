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
    vi parent;
    vi rank;
    int find(int x, vi& parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }
    void union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return ;
        }
        if(rank[x_parent] < rank[y_parent]){
            rank[y_parent] = x_parent;
        }
        else if(rank[x_parent] > rank[y_parent]){
            rank[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int detectCycle(int V, vvi adj){

        parent.resize(V);
        rank.resize(V);

        for(int i = 0; i< V; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for(int u = 0; u<V; u++){
            for(auto& v: adj[u]){
                if(u<v){
                    int parent_u = find(u, parent);
                    int parent_v = find(v, parent);

                    if(parent_u == parent_v){
                        return 1;
                    }
                    union(u, v);
                }
            }
        }
        return 0;
    }

};

