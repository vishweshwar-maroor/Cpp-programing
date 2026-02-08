#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int Partition(vector<int> &arr, int s, int e)
{
    int pivot = s;
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(arr[pivot], arr[pivotIndex]);
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while(arr[i]<arr[pivotIndex]){
            i++;
        }
        while(arr[j]>arr[pivotIndex]){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return (pivotIndex);
}
void QuickSort(vector<int> &arr, int s, int e)
{
    // Base case
    
    if (s >= e)
    {
        return;
    }
    // Partition
    int p = Partition(arr, s, e);

    // Recursive call

    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,};
    
    QuickSort(arr, 0, arr.size() - 1);
    for (int i=0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
}