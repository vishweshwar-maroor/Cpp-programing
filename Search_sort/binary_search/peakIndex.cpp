#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int> &arr)
{
    int first, last, s, e, m, ans;
    s = 0, e = arr.size() - 1;
    m = s + (e - s) / 2;
    ;

    while (s <= e)
    {
        if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1])
        {
            ans = m;
            break;
        }
        else if (arr[m] > arr[m + 1] && arr[m] < arr[m - 1])
        {
            e = m;
        }
        else if (arr[m] < arr[m + 1] && arr[m] > arr[m - 1])
        {
            s = m;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> v = {}
}