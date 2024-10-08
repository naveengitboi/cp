#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, pair<int, pair<int, int>>> mpp;
        long long ans = 0;
        int n = rectangles.size();
        for(int i = 0; i<n; i++){
            double ratio = ((double)rectangles[i][0]/(double)rectangles[i][1]);
            if(mpp.find(ratio) == mpp.end()){
                mpp[ratio].first++;
                mpp[ratio].second.first = i;
            }
            else{
                mpp[ratio].first++;
            }
            mpp[ratio].second.second = i;
        }

        for(int i = 0;i< n; i++){
            double ratio = ((double)rectangles[i][0]/(double)rectangles[i][1]);
            ans = ans + (long long)(mpp[ratio].first - 1);
            mpp[ratio].first -= 1;
        }

        return ans;
    }
};
