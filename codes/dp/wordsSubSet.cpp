// @leet start
// leet code 916 word subset
// this question is somewhat deviated from the usual pattern of leetcode questions
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int m,n;
    void getMap(unordered_map<char, int>& mpp, string word){
        for(auto &ch: word){
            mpp[ch]++;
        }
    }
    bool isMatch(unordered_map<char, int>& mpw ,unordered_map<char, int>& mpc){
        for(auto &it: mpc){
            if(mpw.find(it.first) == mpw.end()){
                return false;
            }
            if(mpw[it.first] < it.second){
                return false;
            }
        }
        return true;
    }
    bool isSubSet(string& word, vector<string>& words2){
        unordered_map<char, int>mpw;
        getMap(mpw, word);
        for(auto &str: words2){
            unordered_map<char, int>mpc;
            getMap(mpc, str);
            if(!isMatch(mpw, mpc)) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        m = words1.size();
        n = words2.size();
        for(int i =0; i< m; i++){
            if(isSubSet(words1[i], words2)){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};
// @leet end


// @leet start
// original answer for 916
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
class Solve {
public:
    int m,n;unordered_map<char, int>universal;

    void getMap(unordered_map<char, int>& mpp, string word){
        for(auto &ch: word){
            mpp[ch]++;
        }
    }
    bool isMatch(unordered_map<char, int>& mpw ,unordered_map<char, int>& mpc){
        for(auto &it: mpc){
            if(mpw.find(it.first) == mpw.end()){
                return false;
            }
            if(mpw[it.first] < it.second){
                return false;
            }
        }
        return true;
    }
    void getUiniversal(vector<string>& words2){
        for(auto &str: words2){
            unordered_map<char, int>mpc;
            getMap(mpc, str);
            for(auto &itr: mpc){
                if(universal.find(itr.first) == universal.end()){
                    universal[itr.first] = itr.second;
                }
                else{
                    universal[itr.first] = max(universal[itr.first], itr.second);
                }
            }
        }
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        m = words1.size();
        n = words2.size();
        getUiniversal(words2);
        for(int i =0; i< m; i++){
            unordered_map<char, int> mpp;
            getMap(mpp, words1[i]);
            if(isMatch(mpp, universal)){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};
// @leet end
