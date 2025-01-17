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
    int spanningTree(int V, vvi& adj) {
        priority_queue<pii, vector<pii> , greater<pii>> pq;
        pq.push({0,0});
        vector<bool> inMst(V, false);
        while(!pq.empty()){
            auto top = pq.top();
            int wt = top.first;
            int node = top.second;

            if(inMst[node]){
                continue;
            }
            inMst[node] = true;
            sum+= wt;
            for(auto& edge: adj[node]){
                int v = edge[0];
                int dist = edge[1];

                if(inMst[v] == false){
                    pq.push({dist, v});
                }

            }

        }
        return sum;
    }
};

