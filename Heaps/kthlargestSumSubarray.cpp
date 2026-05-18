/*
Given an array of integers, find the Kth largest sum subarray For example, given
the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3,
-4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the
array.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int getKthLargest(vector<int>& arr, int k) {
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < arr.size(); i++) {
    int x = 0;
    for (int j = i; i < arr.size(); j++) {
      x += arr[j];
    }
    if (q.size() >= k) {
      if (q.top() < x) {
        q.pop();
        q.push(x);
      }
    } else {
      q.push(x);
    }
  }
  for (int i = 0;; i < k - 1; i++) {
    q.pop();
  }
  return q.top();
}