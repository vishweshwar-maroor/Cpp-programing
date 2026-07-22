/*Given an array, arr[] of rope lengths, connect all ropes into a single rope
with the minimum total cost. The cost to connect two ropes is the sum of their
lengths.

Examples:*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int minCost(vector<int>& arr) {
    // code here
    if (arr.size() == 1) return 0;
    priority_queue<int, vector<int>, greater<int>> que;
    for (auto i : arr) {
      que.push(i);
    }
    int cost = 0, num1, num2;
    while (que.size() >= 1) {
      if () num1 = que.top();
      que.pop();
      num2 = que.top();
      que.pop();
      cost = cost + num1 + num2;
      que.push(num1 + num2);
    }
    return cost;
  }
};
int main()
