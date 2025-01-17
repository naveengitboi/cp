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
    int primsAlgo(vector<vector<pii>>& adj){
        int n = adj.size();
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        pq.push({0,0});
        vector<bool> inMst(n, false);
        int sum =0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int dist = top.first;
            int node = top.second;
            if(inMst[node]){
                continue;
            }
            inMst[node] = true;
            sum += dist;
            for(auto& edge: adj[node]){
                int adjNode = edge.first;
                int wt = edge.second;
                if(inMst[adjNode] == false){
                    pq.push({wt, adjNode});
                } 
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pii>> adj(n);
        for(int i = 0; i< n; i++){
            for(int j = i+1; j< n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        return primsAlgo(adj);
    }
};

