#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>


class Solution {
public:
    int getNum(string v){
        int num = 0;
        for(int i = 0; i< v.length(); i++){
            num = num*10 + (v[i] - '0');
        }
        return num;
    }
    int compareVersion(string v1, string v2) {
        int n1  = v1.size();
        int n2  = v2.size();
        int n = max(n1, n2);
        int i =0;
        vi a;
        vi b;
        string s1,s2;
        while( i < n){
            if(i < n1){
                if(v1[i] == '.' or i == n1 - 1){
                    a.push_back(getNum(s1));
                    s1 = "";
                }
                s1 += v1[i];
            }
            if(i < n2){
                if(v2[i] == '.' or i == n2 - 1){
                    b.push_back(getNum(s2));
                    s2 = "";
                }
                s2 += v2[i];
            }
            i++;
        }
        int j = 0;
        int k = 0;
        while(j < a.size() && k < b.size()){
            if(a[j] == b[k]){
                j++;
                k++;
            }else if(a[j] < b[j]){
                return -1;
            }else{
                return 1;
            }
        }
        while(j < a.size()){
            if(a[j] != 0){
                return 1;
            }
            j++;
        }
        while(k < b.size()){
            if(b[k] != 0){
                return -1;
            }
            k++;
        }
        return 0;
    }
};

