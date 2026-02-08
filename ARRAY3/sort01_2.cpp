#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}
void sort(vector<int> &v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i <= j)
    {
        if (v[i] == 0)
            i++;
        if (v[j] == 1)
            j--;
        else if (v[j] == 0 && v[i] == 1)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    
}
int main()
{
    
    vector<int> v({1,1,0,1,0,1,1,0});
    sort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}