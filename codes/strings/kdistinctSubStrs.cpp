#include <bits/stdc++.h>
using namespace std;

long long getAnswer(string s, int k){

    long long count = 0, ans = 0;
    vector<int> vect(26,0);
    int i =0;
    int j = 0;
    int n = s.length();
    while(j < n){
        int idx = s[j] - 'a';
        if(vect[idx] == 0) count++;
        vect[idx]++;

        while(count == k){
            ans += (n-j);
            vect[s[i] - 'a']--;
            if(vect[s[i] - 'a'] == 0){
                count--;
            }
            i++;
        }
        j++;
    }

    return ans;
}

long long substringCount(string s, int k){
    return getAnswer(s, k) - getAnswer(s, k+1);
}
