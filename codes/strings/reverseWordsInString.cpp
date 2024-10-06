#include <bits/stdc++.h>
using namespace std;

string reverseWords(string text){
    int n = text.length();
    string ans ="";
    string word = "";
    bool seen = false;
    for(int i = n-1; i>=0; i--){
        if(text[i] == ' '){
            ans += word;
            if(seen){
                ans += ' ';
            }
            seen = false;
            word = "";
        }
        else{
            word = text[i] + word;
            seen = true;
        }
    }
    if(text[0] != ' '){
        ans += word;
    }
    return ans;
}
