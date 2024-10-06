#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s1, string s2){
    unordered_map<char, int>mpp1;
    unordered_map<char, int>mpp2;
    if(s1.length() != s2.length()) return false;
    for(int i =0; i< s1.length(); i++){
        mpp1[s1[i]]++;
        mpp2[s2[i]]++;
    }
    for(auto p: mpp1){
        if(mpp2.find(p.first)== mpp2.end()) {
            return false;
        }
        if(mpp2[p.first] != p.second){
            return false;
        }
    }
    return true;
}
