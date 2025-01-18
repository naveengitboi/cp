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
    int minMutation(string start, string end, vector<string>& bank){
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;

        queue<string> q;
        q.push(start);
        visited.insert(start);

        int level = 0;
        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();
                
                if(curr == end) return level;

                for(auto& c: "ACGT"){
                    for(int i = 0; i< curr.length(); i++){
                        string dummy = curr;
                        dummy[i] = c;
                        if(bankSet.find(dummy) != bankSet.end() && visited.find(dummy) == visited.end()){
                            visited.insert(dummy);
                            q.push(dummy);
                        }
                        
                    }
                }
            }
            level++;
        }

        return -1;

        
    }
};

