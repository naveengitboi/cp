#include <bits/stdc++.h>
using namespace std;



//approach optimazation
//
//

bool checkInclusion(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<int> s1map(m, 0);
    vector<int> s2map(n, 0);

    int j = 0;
    int i = 0;
    while(j< n){
        s2map[s2[j] - 'a']++;
        if(j-i+1 > n){
            //shrink window
            s2map[s2[i]-'a']--;
            i++;
        }
        if(s2map == s1map){
            return true;
        }
        j++;
    }
    return false;
}
