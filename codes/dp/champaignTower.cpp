// @leet start
// champagneTower 799 leetcode question
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double getNcr(int n, int r){
        int den = 1;
        int last = min(n-r, r);
        double ans = 1;
        for(int i = n; i> last;i--){
            ans = ans*((double)i/(double)den);
            den++;
        }
        return ans;
    }
    vector<int> quants(int row){
        vector<int> ans(row+1);
        ans[0] = 1;
        ans[row] =1;
        for(int i =1;i<row; i++){
            ans[i] = getNcr(row, i);
        }
        return ans;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<int> row = quants(query_row);
        int n = query_row + 1;
        double total = 0;
        for(auto num: row){
            total += (double)num;
            cout<< num <<" ";
        }
        cout<<endl;
        int neededToFillAll =(n)*(n+1)/2;
        int beforeRow = (n-1)*(n)/2;
        cout<<total << " "<< neededToFillAll <<" "<< beforeRow<<endl;
        if(poured >= neededToFillAll){
            return (double)1;
        }
        if(beforeRow > poured){
            return (double)0;
        }
        return (poured - beforeRow)*((double)row[query_glass]/(double)total);

    }
};
// @leet end
