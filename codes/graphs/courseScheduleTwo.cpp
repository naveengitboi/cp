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
    vi topoSort(map<int, vi>& adj,int n, vi& indegree){
        queue<int> q;
        int cnt = 0;
        vi ans;
        for(int i = 0; i< n; i++){
            if(indegree[i] == 0){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto p: adj[node]){
                indegree[p]--;
                if(indegree[p] == 0){
                    q.push(p);
                    cnt++;
                }
            }
        }
        if(cnt != n){
            return {};
        }
        return ans;
    }
    vi findOrder(int numCourses, vvi& prerequisites){
        map<int, vi> adj;
        vi indegree(numCourses, 0);
        for(auto vect: prerequisites){
            int a = vect[0];
            int b = vect[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topoSort(adj, numCourses, indegree);

    }
};

