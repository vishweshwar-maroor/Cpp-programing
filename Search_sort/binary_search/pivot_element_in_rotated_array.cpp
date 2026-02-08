#include <iostream>
#include <vector>
using namespace std;
int pivotIndexInRotaterArray(vector<int> &arr)
{
    int s, e, m, ans;
    s = 0, e = arr.size() - 1;
    m = s + (e - s) / 2;
    
    while (s <= e)
    {
        if (arr[m]>arr[m+1]||arr[m]<arr[m-1])
        {
            ans = m;
            break;
        }
        else if (arr[m] > arr[0])
        {
            s=m;
        }
        else if (arr[m] <arr[0])
        {
            e = m;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> v = {4,5,1,2,3};
    cout<<pivotIndexInRotaterArray(v);
}