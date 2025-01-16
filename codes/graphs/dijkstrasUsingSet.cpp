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
    vi dijkstrasUsingSet(int n, vvi adj, int src){
        set<pii> st;
        //pair<distance, node>
        vi result(n, INT_MAX);

        st.insert({0, src});

        while(!st.empty()){
            auto &it = *st.begin();
            int dist = it.first;
            int node = it.second;

            st.erase(it);

            for(auto& vec: adj[node]){
                int adjNode = vec[0];
                int wt = vec[1];
                if(dist+wt < result[adjNode]){
                    if(result[adjNode] != INT_MAX){
                        st.erase({result[adjNode], adjNode});
                    }
                    result[adjNode] = dist+wt;
                    st.insert({dist+wt, adjNode});
                }
            }

        }
        return result;

    }
};

