// @leet start
// champagneTower 799 leetcode question
// @leet start
// correct answer
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
class SolveProblem {
public:
    double dp[101][101];
    double solve(int poured, int i, int j){
        if(i < 0 || j <0 || i< j) {
            return 0.0;
        }
        if(i == 0&& j == 0){
            return poured;
        }
        if(dp[i][j] != -1.0) return dp[i][j];
        double leftUp = (solve(poured, i-1, j-1)-1)/2.0;
        double rightUp = (solve(poured, i-1, j)-1)/2.0;
        if(leftUp < 0) leftUp = 0.0;
        if(rightUp < 0) rightUp = 0.0;
        return dp[i][j] = leftUp + rightUp;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i = 0 ;i <101; i++){
            for(int j = 0; j< 101 ;j++){
                dp[i][j] = -1.0;
            }
        }
        double ans = solve(poured, query_row, query_glass);
        return min(1.0, ans);
    }
};
// @leet end
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
