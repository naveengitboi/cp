#include <bits/stdc++.h>
#include <climits>
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


int smallestNumber(int n){
	while(1){
		int i = 11;
		for(i; i <= 20; i++){
			if(n%i != 0){
				break;
			}
		}
		if(i == 21){
			break;
		}
		n++;
	}
	return n;
}

int main() {
    int t;
	cout<<"enter number";
    cin>>t;

	int ans = smallestNumber(t);
	cout<<ans<<endl;
    return 0;
}


