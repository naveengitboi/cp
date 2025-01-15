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
    vi dijkstra(int n, vvi& adj, int src){
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        //min heap initilization
        //
        vi result(n, INT_MAX);
        result[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            pii minTop = pq.top();
            int currDist = minTop.first;
            int currNode = minTop.second;

            for(auto& vect: adj[currNode]){
                int wt = vect[1];
                int adjNode = vect[0];

                if(wt + currDist < result[adjNode]){
                    result[adjNode] = wt + currDist;
                    pq.push({wt+currDist, adjNode});
                }
            }

        }
        return result;

    }
};

