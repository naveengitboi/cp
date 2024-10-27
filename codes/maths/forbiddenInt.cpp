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

void print(vi& vect){
    cout<<vect.size()<<endl;
    for(int i =  0; i< vect.size(); i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}
void solve(int n, int k, int x){
    if(k == 1 && x == 1){
        cout<<"NO"<<endl;
        return;
    }
    int sum = n; 
    vi vect;
    while(true){
        bool useFul = false;
        for(int i = k; i>= 1 ; i--){
            if(i != x && sum - i >= 0){
                sum-=i;
                vect.push_back(i);
                useFul = true;
            }
            if(sum == 0){
                break;
            }
        }
        if(!useFul){
            break;
        }
    }
    if(sum != 0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int p = vect.size();
    cout<<p<<endl;
    print(vect);

}

void forbiddenInt(int n, int k, int x){
    if(x != 1){
        vi vect(n, 1);
        cout<<"YES"<<endl;
        print(vect);
    }
    else{
        if(k == 1){
            cout<<"NO"<<endl;
        }
        else if(!(n&1)){
            int p = n/2;
            vi vect(p, 2);
            cout<<"YES"<<endl;
            print(vect);
        }else{
            if(k>= 3){
                int p = n/2 - 1;
                vi vect(p, 2);
                vect.push_back(3);
                cout<<"YES"<<endl;
                print(vect);
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k, x;
        cin>>n>>k>>x;
        forbiddenInt(n, k, x);
    }

    return 0;
}


