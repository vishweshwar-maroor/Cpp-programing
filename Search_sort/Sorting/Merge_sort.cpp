#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> &arr, int start, int end)
{
    int k = start;
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;


    // Creating exxtra array
    
    vector<int> L(len1), R(len2);
    
    // Putting elements in array
    
    for (int i = 0; i < len1; i++)
    {
        L[i] = arr[start + i];
    }
    for (int i = 0; i < len2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    // Sorting 2 sorted array
    
    int index1 = 0, index2 = 0;
    
    while (index1 < len1 && index2 < len2)
    {
        if (L[index1] <= R[index2])
        {
            arr[k++] = L[index1++];
        }
        else
        {
            arr[k++] = R[index2++];
        }
    }
    
    while (index1 < len1)
    {
        arr[k++] = L[index1++];
    }
    
    while (index2 < len2)
    {
        arr[k++] = R[index2++];
    }
}
void MergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    // Break Left
    MergeSort(arr, start, mid);
    // Break Right
    MergeSort(arr, mid + 1, end);
    // Merge
    Merge(arr, start, end);
}
int main()
{
    vector<int> arr={1,5,3,6,8,9,6,4,7,2,12,15,6,8,69};
    MergeSort(arr,0,8);
    for(int i:arr){
        cout<<i<<" ";
    }
}