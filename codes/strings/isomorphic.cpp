#include <bits/stdc++.h>
using namespace std;


bool isomorphic(string s1, string s2){
    unordered_map<char, char>mpp1;
    unordered_map<char, char>mpp2;
    int m = s1.length();
    int n = s2.length();

    if(m != n) return false;
    for(int i = 0; i< m; i++){
        char c1 = s1[i];
        char c2= s2[i];
        if(mpp1.find(c1) != mpp1.end()){
            if(mpp1[c1] != c2){
                return false;
            }
        }
        if(mpp2.find(c2) != mpp2.end()){
            if(mpp2[c2] != c1){
                return false;
            }
        }
        mpp1[c1] = c2;
        mpp2[c2] = c1;
    }
    return true;
}
