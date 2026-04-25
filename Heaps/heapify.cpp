#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
  int largest = i;
  int l = 2 * i;  // 2 * i; is for one based indexing for zero based indexing
                  // use 2*i +1
  int r = 2 * i + 1;
  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}
void buildheap(vector<int>& arr) {
  int n = arr.size();
  int index = arr.size() / 2 - 1;
  for (int i = index; i >= 0; i--) {
    heapify(arr, n, i);
  }
}
int main()