#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < lists.size(); i++) {
      ListNode* temp = lists[i];
      while (temp != NULL) {
        q.push(temp->val);
        temp = temp->next;
      }
    }
    ListNode* root = NULL;
    ListNode* tail = NULL;
    root = new ListNode(q.top());
    q.pop();
    tail = root;
    while (!q.empty()) {
      tail->next = new ListNode(q.top());
      q.pop();
      tail = tail->next;
    }
    return root;
  }
};
int main()