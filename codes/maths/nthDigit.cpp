// @leet start
// nth digit 400 leetcode question
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef long long ll;
    int findNthDigit(int n) {
        ll total = 0;
        ll digit = 1;
        ll multiple = 9;
        if(n < 9) return n;
        while(total + digit*multiple < n){
            total += digit*multiple;
            digit++;
            multiple = multiple*10;
        }
        n -= total;
        int num = pow(10, digit-1);
        num += (n-1)/digit;
        int idx = (n-1)%digit;
        string str = to_string(num);
        int val = str[idx] -'0';
        return val;
    }
};
// @leet end
