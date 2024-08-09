#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int max_sum = nums[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      max_sum = max(max_sum, sum);
      if (sum < 0) {
        sum = 0;
      }
    }
    return max_sum;
  }

  vector<int> twoSum(vector<int> &arr, int target) {
    int i = 0; int j = arr.size() - 1;
    while(i < j) {
      if (arr[i] + arr[j] == target) {
      return {i, j};
      } else if (arr[i] + arr[j] < target) {
      i++;
      } else {
      j--;
      }
    }
  }
};
