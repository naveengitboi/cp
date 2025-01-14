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
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;

        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else if(rank[parent_y] < rank[parent_x]){
            parent[parent_y] = parent_x;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vvi& connections){
        int e = connections.size();
        if(e <  n-1) return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i< n; i++){
            parent[i] = i;
        }
    
        int components = n;
        for(auto& v: connections){
            int parent_x = find(v[0]);
            int parent_y = find(v[1]);
            if(parent_x != parent_y){
                Union(v[0], v[1]);
                components--;
            }
        }
        return components-1;
    }
};

