/*Merge Two Binary Max Heaps
same as merging bt*/
#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void buildheap(vector<int> &arr)
{

    int n = arr.size();
    int index = arr.size() / 2 - 1;
    for (int i = index; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    buildheap(arr1);
    return arr1;

}