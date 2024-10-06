#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& words){
    string ans = "";
    int k = 0;
    bool isExit = false;
    while(!isExit){
        bool same = true;
        char ref;
        for(int i=0; i< words.size() ; i++){
            if(k == words[i].length()){
                isExit = true;
                break;
            }
            if(i == 0){
                ref = words[i][k];
            }
            else{
                if(ref != words[i][k]){
                    same = false;
                    isExit = true;
                }
            }
        }
        if(same && !isExit){
            ans += words[0][k];
        }
        k++;
    }
    return ans;
}
