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
    private:
    vi parent;
    vi rank;
public:
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
        }else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    ll countPairs(int n, vvi& edges){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i< n; i++){
            parent[i] = i;
        }

        for(auto& vec: edges){
            int u = vec[0];
            int v = vec[1];

            Union(u, v);
        }

        map<int, int> mp;

        for(int i = 0; i< n; i++){
            int parent_i = find(i);
            mp[parent_i]++;
        }
        ll result = 0;
        int rem = n;
        for(auto& p: mp){
            int size = p.second;
            result+= (size)*(rem - size);
            rem -= size;
        }

        return result;
    }
};

