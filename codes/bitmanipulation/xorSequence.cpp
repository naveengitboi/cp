#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long


long getXor(long num){
  long n = num%8;
  
  if(n == 0 || n == 1) return num;
  else if(n == 2 || n == 3) return 2;
  else if(n == 4 || n == 5) return num + 2;
  else {
    return 0;
  }
}

long xorSequence(long l, long r) {

  return getXor(l-1) ^ getXor(r);

}

long sumXor(long n){

  long ans;
  long cnt;
  while(n){
    long t = n&1;
    if(t == 0){
      cnt++;
    }
    n>>=1;
  }

  return ans<<cnt;
}

int main(){

  long l;
  long r;
  cin>>l;
  cin>>r;

  cout<< xorSequence(l, r);

  return 0;
}
