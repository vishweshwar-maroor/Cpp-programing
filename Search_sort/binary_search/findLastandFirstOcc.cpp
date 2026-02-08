#include <iostream>
#include <vector>
using namespace std;
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    
    int first, last, s, e, m,ansf,ansl;
    s = 0, e = n - 1;
    m = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[m] == k)
        {
            ansf=m;
            e=m-1;
        }
        else if (arr[m] > k)
        {
            e = m - 1;
        }
        else if (arr[m] < k)
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
        if(arr[ansf-1]!=arr[ansf]){
            break;
        }

    }
    s = 0, e = n - 1;
    m = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[m] == k)
        {
            ansl=m;
            s=m+1;
        }
        else if (arr[m] > k)
        {
            e = m - 1;
        }
        else if (arr[m] < k)
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
        if(arr[ansl+1]!=arr[ansl]){
            break;
        }

    }
    pair<int,int> p={ansf,ansl};
    
    return p;
}

int FirstOcc(vector<int> arr, int key)
{
    int first, last, s, e, m,ans;
    s = 0, e = arr.size() - 1;
    m = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[m] == key)
        {
            ans=m;
            e=m-1;
        }
        else if (arr[m] > key)
        {
            e = m - 1;
        }
        else if (arr[m] < key)
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
        if(arr[ans-1]!=arr[ans]){
            return ans;
        }

    }
    
}
int LastOcc(vector<int> arr, int key)
{
    int first, last, s, e, m,ans;
    s = 0, e = arr.size() - 1;
    m = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[m] == key)
        {
            ans=m;
            s=m+1;
        }
        else if (arr[m] > key)
        {
            e = m - 1;
        }
        else if (arr[m] < key)
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
        if(arr[ans+1]!=arr[ans]){
            return ans;
        }

    }
    
}

int main()
{
    int n;
    cout << "put size of array :";
    cin >> n;
    vector<int> arr(n);
    cout << "put values :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "put integer to find :";
    int key;
    cin >> key;
    // cout<<FirstOcc(arr, key)<<endl;
    // cout<<LastOcc(arr,key);
    pair<int,int> p=firstAndLastPosition(arr,n,key);
    cout<<p.first<<p.second;
}