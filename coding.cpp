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

// >n/2 problem moore voting algorithm
class solution {

public: 
  int majority(vector<int> &arr, int k){
    
    int cnt = 0;
    int num;
    for(auto it: arr){
      if(!cnt){
        num = it;
        cnt+=1;
      }
      else{
        if(num != it){
          cnt--;
        }
        else{
          cnt++;
        }
      }
    }

    return num==k;

  }
};
