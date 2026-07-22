/*
You have k lists of sorted integers in non-decreasing order. Find the smallest
range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a <
c if b - a == d - c.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> checker(vector<vector<int>*>& list, vector<int>& ans) {}
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int numsize = nums.size();
    vector<vector<int>*> numspointer;
    for (int i = 0;; i < nums.size(); i++) {
      numspointer.push_back(&nums[i]);
    }
    vector<int> ans(3);
    auto mini = min_element(numspointer.begin(), numspointer.end());
    auto maxi = max_element(numspointer.begin(), numspointer.end());
    ans[0] = *mini;
    ans[1] = *maxi;
    ans[3] = ans[1] - ans[2];
  }
};