// @leet start
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    typedef pair<int, char> p;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<p> heap;
        if(a > 0) heap.push({a, 'a'});
        if(b > 0) heap.push({b, 'b'});
        if(c > 0) heap.push({c, 'c'});
        string result="";
        while(!heap.empty()){
            int currCount = heap.top().first;
            char currChar = heap.top().second;
            heap.pop();
            int l = result.length();
            if(l>= 2 && result[l-1] == currChar && result[l-2] == currChar){
                //dont use
                if(heap.empty()) break;
                int nextCount = heap.top().first;
                char nextChar = heap.top().second;
                heap.pop();
                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0){
                    heap.push({nextCount, nextChar});
                }
            }else{
                result.push_back(currChar);
                currCount--;
            }
            if(currCount > 0){
                heap.push({currCount, currChar});
            }
        }

        return result;
    }
};
// @leet end
