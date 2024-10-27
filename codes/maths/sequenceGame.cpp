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

void printVect(vi nums){
    int n = nums.size();
    cout<<n<<endl;
    for(int i = 0; i< n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi arr(n);
        vi nums;
        int prev = -1;
        for(int i = 0; i< n; i++){
            cin>>arr[i];
        }
        nums.push_back(arr[0]);
        for(int i = 1; i< n; i++){
            if(arr[i] >= arr[i-1]){
                nums.push_back(arr[i]);
            }
            else{
                nums.push_back(arr[i]);
                nums.push_back(arr[i]);
            }
        }
        printVect(nums);
    }

    return 0;
}


