#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr):data(data), next(next) {}
};

class solution{
public:
    Node* st;
    int top;
    solution(){
        top = -1;
    }
    int push(int num){
        if(empty()){
            st = new Node(num);
            top++;
        }else{
            Node* temp = new Node(num);
            temp->next = st;
            st = temp;
            top++;
        }
        return 0;
    }
    int pop(){
        if(empty()){
            return -1;
        }
        int val = st->data;
        st = st->next;
        top--;
        return val;
    }
    int topElement(){
        if(empty()){
            return -1;
        }
        return st->data;
    }

    bool empty(){
        return top == -1;
    }
};
