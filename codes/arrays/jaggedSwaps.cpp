#include <algorithm>
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


bool solve(int n, vi& nums){
    int mini =  *min_element(nums.begin(), nums.end());
    if(nums[0] !=mini){
        return false;
    }
    else{
        for(int i = 0; i < n; i++){
            bool isFound = false;
            for(int j = 1; j< n-1; j++){
                if(nums[j] > nums[j-1] && nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    isFound = true;
                }
            }
            if(!isFound){
                break;
            }
        }
        vi temp = nums;
        sort(temp.begin(), temp.end());
        if(temp == nums) return true;
        return false;
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vi vect(n);
        for(int i = 0; i< n; i++){
            cin>>vect[i];
        }
        bool ans = solve(n, vect);
        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}


