#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> &u, vector<int> &v)
{
    vector<int> r;
    int i = 0, j = 0;
    while (r.size() != v.size() + u.size())
    {
        if(i>=v.size()){
            while(r.size() != v.size() + u.size()){
                r.push_back(u[j]);
                j++;
            }
        }
        if(j>=u.size()){
            while(r.size() != v.size() + u.size()){
                r.push_back(v[i]);
                i++;
            }
        }        
        else if (v[i] < u[j])
        {
            r.push_back(v[i]);
            i++;
        }
        else if (v[i] > u[j])
        {
            r.push_back(u[j]);
            j++;
        }
        else if (v[i] == u[j])
        {
            r.push_back(v[i]);
            i++;
            j++;
        }
    }
    return r;
}
int main()
{
    vector<int> arr1 = {1,6,8,9};
    vector<int> arr2 = {2,3,4,5,7};
    // vector<int> res = merge(arr1, arr2);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i]<<" ";
    // }
    arr1.swap(arr2);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i]<<" ";
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i]<<" ";
    }

    
    
}