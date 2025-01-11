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

class stack{
public: 
    int top;
    int* arr;
    int cap;
    Stack(int capacity){
        arr = new int[capacity];
        top = -1;
        cap = capacity;
    }
    int push(int num){
        if(!full()){
            top++;
            arr[top] = num;
        }
        else{
            return -1;
        }
    }
    int pop(){
        if(empty()){
            return -1;
        }
        return arr[top--];
    }
    int topElement(){
        if(top == -1) return -1;
        return arr[top];
    }
    bool empty(){
        return top == -1;
    }
    bool full(){
        return top == cap-1;
    }
    int size(){
        return top+1;
    }
}




int main() {
    int t;
    cin>>t;
    while(t--){

    }

    return 0;
}


