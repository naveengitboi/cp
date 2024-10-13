// @leet start
// minimum area of rectangle 939
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int minArea  = INT_MAX;
        int n = points.size();
        if(n < 4) return 0;
        set<pair<int,int>> hashSet;
        for(int i = 0; i< n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(auto p: hashSet){
                int x2 = p.first;
                int y2 = p.second;
                if(hashSet.find({x1,y2}) != hashSet.end() && hashSet.find({x2, y1}) != hashSet.end()){
                    int area = abs(x2-x1)*abs(y2-y1);
                    minArea = min(minArea, area);
                }
            }
            hashSet.insert({x1,y1});
        }
        if(minArea != INT_MAX){
            return minArea;
        }
        return 0;
    }
};
// @leet end
