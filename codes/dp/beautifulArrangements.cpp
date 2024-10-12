// @leet start
// beautiful arrangements problem from leetcode number 526
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution {
public:
    void getPermutes(int n, int pos, vi& visited, int& count){
        if(pos > n) count++;
        for(int i = 1; i<=n ; i++){
            if(!visited[i] && (i%pos == 0 or pos%i == 0)){
                visited[i] = true;
                getPermutes(n,pos+1, visited, count);
                visited[i] = false;
            }
        }
        
    }
    int countArrangement(int n) {
        int count = 0;
        int pos = 1;
        vi visited(n+1, false);
        getPermutes(n, pos, visited, count);
        return count;
    }
};
// @leet end
