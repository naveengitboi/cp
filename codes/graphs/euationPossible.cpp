//leetcode 990
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
    void union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        } else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationPossible(vs& equations){
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i<26; i++){
            parent[i] = i;
        }

        for(string& s: equations){
            if(s[1] == '='){
                // make union
                //
                union(s[0]-'a', s[3]-'a');
            }
        }

        for(string& s:equations){
            if(s[1] == '!'){
                int parent_x = find(s[0] - 'a');
                int parent_y = find(s[3] - 'a');
                if(parent_x == parent_y){
                    return false;
                }
            }
        }
        return true;
    }
};

