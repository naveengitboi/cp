#include <bits/stdc++.h>
using namespace std;

void makeLPS(vector<int>& lps, string pattern){
    lps[0] = 0;
    int n = pattern.length();
    int i = 0;
    int j = 1;
    while(j < n){
        if(pattern[i] == pattern[j]){
            lps[j] = i+1;
            i++;
            j++;
        }else{
            if(i!= 0){
                i = lps[i-1];
            }else{
                j+=1;
            }
        }
    }
    return;
}

int patternMatching(string text, string pattern){
    int m = text.length();
    int n = pattern.length();
    vector<int> lps(n);

    makeLPS(lps,pattern);

    int i =0, j =0;
    while(i < m){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
        if(j == n){
            return i-j;
        }
    }
    return -1;
}
