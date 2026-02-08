/*Find the doublet in the Array whose sum is
equal to the given value x. */
#include <iostream>
#include <vector>
using namespace std;
void twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "[" << i << "," << j << "]";
                cout << "[" << nums[i] << "," << nums[j] << "]" << endl;
            }
        }
    }
}
int main()
{
    int n;
    cout << "number of elements in array :";
    cin >> n;
    vector<int> arr(n);
    cout << "put elements of array";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "put target";
    cin >> target;
    twoSum(arr, target);
}