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
    vi size;
    int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y){
            return;
        }

        if(size[parent_x] > size[parent_y]){
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
        else if(size[parent_x] < size[parent_y]){
            parent[parent_x] = parent_y;
            size[parent_y]+= size[parent_x];
        }else {
            parent[parent_x] = parent_y;
            size[parent_y]+= size[parent_x];
        }
    }

    void DisjointSetBySize(vvi adj){
        int V = adj.size();
        for(int u = 0; u<V; u++){
            for(auto& v: adj[u]){
                Union(u, v);
            }
        }
    }
};

