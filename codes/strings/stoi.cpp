#include <bits/stdc++.h>
#include <climits>
using namespace std;


int stringToInteger(string s){
    long long ans = 0;
    int i = 0;
    int n = s.length();
    int sign = 1;
    while(i < n && s[i] == ' '){
        i++;
    }
    if(i<n && s[i] == '-'){
        sign = -1;
        i++;
    }
    for(;i< n;i++){
        char c = s[i];
        if(c >= '0' && c<= '9'){
            ans = ans*10 + (c-'0');
        }
        if(ans > INT_MAX && sign == 1){
            return INT_MAX;
        }
        if(-ans < INT_MIN && sign == -1){
            return INT_MIN;
        }

    }


    return ans;
}
