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
    int kruskalsMST(int V, vvi& vect){
        for(auto& edge: vect){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);
            if(parent_u != parent_v){
                Union_(u, v);
                sum += wt;
            }
        }
        return sum;
    }

    int find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }

    int spanningTree(int V, vvi adj[]){
        vvi vect;
        parent.resize(V);
        rank.resize(V, 0);

        for(int i = 0; i< V; i++){
            parent[i] = i;
        }
        
        for(int u =0 ; u <V ; u++){
            for(auto& edge: adj[u]){
                int v = edge[0];
                int wt = edge[1];

                vect.push_back({u, v, wt});
            }
        }

        auto compare = [&](vi& a, vi& b){
            return a[2]< b[2];
        };

        sort(begin(vect), end(vect), compare);

        return kruskalsMST(V, vect);

    }
};

