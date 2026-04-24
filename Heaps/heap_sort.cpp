#include <iostream>
#include <vector>
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
// loop
void heapsorterloop(vector<int> &arr, int size)
{
    for (int i = size; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// recursive
void heapsorter(vector<int> &arr, int size)
{
    if (size <= 0)
        return;
    swap(arr[0], arr[size]);
    size--;
    heapify(arr, size, 0);
}
void heapsort(vector<int> &arr)
{
    int size = arr.size() - 1;
    buildheap(arr);
}
int main()