#include <bits/stdc++.h>
using namespace std;

string sortChars(string s){
    string ans = "";
    vector<pair<int, char>> vect(60);
    int n = s.length();
    for(int i = 0; i< n; i++){
        vect[s[i] - 'a'].first ++;
        vect[s[i] - 'a'].second = s[i];
    }
    sort(vect.begin(), vect.end());
    int i = 59;
    while(i){
        while(vect[i].first--){
            ans += vect[i].second;
        }
        i--;
    }

    return ans;
}
