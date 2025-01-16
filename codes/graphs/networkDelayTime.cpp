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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pii>> adj;
        for(auto& vec: times){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v, wt});
            //directed graph
            //adj[v].push_back({u, wt});
        }

        vi result(n+1, INT_MAX);
        result[k] = 0;//source dist 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int dist  = pq.top().first;
            int node  = pq.top().second;
            pq.pop();

            for(auto &vec: adj[node]){
                int adjNode = vec[0];
                int wt = vec[1];

                int newDist = wt + dist;
                if(newDist < result[adjNode]){
                    result[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                }
            }
        }

        int ans = 0;
        for(auto &time: result){
            if(time == INT_MAX) return -1;
            ans = max(ans, time);
        }
        return ans;



    }
};

