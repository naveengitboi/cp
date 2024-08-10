#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node(int data, Node* next): data(data), next(next) {};
  Node(int data) : data(data), next(nullptr) {};
};

class solution {
public:
  Node* sortList(Node* head) {

    Node* curr = head;
    vector<int> nums;
    while(curr){
      nums.push_back(curr->data);
      curr = curr->next;
    }

    sort(nums.begin(), nums.end());

    Node* temp = head;
    for(int i =0; i< nums.size(); i++){
      temp->data = nums[i];
      temp = temp->next;
    }
    return head;

  }
};
