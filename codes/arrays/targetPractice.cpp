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



int solve(int n, vs& vect){
    int ans = 0;
    int level = 1;
    int left = 0, right = n - 1, top = 0, down = n-1;
    while(left <= right && top <= down){
        //left to right
        for(int j = left; j<=right; j++){
            if(vect[top][j] == 'X'){
                ans += level;
            }
        }
        top++;

        // top to down
        for(int j = top; j <= down; j++){
            if(vect[j][right] == 'X'){
                ans += level;
            }
        }
        right--;
        //right to left
        for(int j = right; j >= left; j--){
            if(vect[down][j] == 'X'){
                ans += level;
            }
        }
        down--;
        //down to top
        for(int j = down; j >= top ; j--){
            if(vect[j][left] == 'X'){
                ans += level;
            }
        }
        left++;
        level++;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n = 10;
        vs vect(n);
        for(int i = 0; i< n; i++){
            string s;
            cin>>s;
            vect[i] = s;
        }
        int ans = solve(n , vect);
        cout<<ans<<endl;
    }

    return 0;
}


