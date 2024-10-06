#include <bits/stdc++.h>
using namespace std;


int maxNestingDepth(string s){
    int maxDepth = INT_MIN;
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i< n; i++){
        if(s[i] == '('){
            cnt++;
        }
        if(s[i] ==')'){
            maxDepth = max(maxDepth, cnt);
            cnt--;
        }
    }

    return maxDepth;
}
