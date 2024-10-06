#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int top;
    int capacity;
    vector<int> st;
    Stack(int capacity){
        top = -1;
        this->capacity = capacity;
    }
    int push(int num){
        if(capacity > top){
            st[++top] = num;
        }
        return 1;
    }
    int pop(){
        if(empty()){
            return -1;
        }
        return st[top--];
    }
    int topElement(){
        if(empty()){
            return -1;
        }
        return st[top];
    }

    bool empty(){
        return top == -1; 
    }
    bool full(){
        return top + 1== capacity;
    }
    int size(){
        return top +1;
    }
};
