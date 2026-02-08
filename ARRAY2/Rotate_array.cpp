#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void revpart(vector<int> &v, int size, int s, int e)
{
    for (int i = s, j = e; i <= j; i++, j--)
    {
        swap(v[i], v[j]);
    }
}
void rotate(vector<int> &v, int size, int k )
{
    int steps=k%size;
    revpart(v, size, 0, size - steps - 1);
    revpart(v, size, size - steps, size - 1);
    revpart(v, size, 0, size - 1);
}
int main()
{
    int size;
    cout << "put no of elements ";
    cin >> size;
    vector<int> v;
    //input
    cout<<"put elements";
    for (int i = 0; i < size; i++)
    {
        int q;
        cin >> q;
        v.push_back(q);
    }
    int k;
    cout << "put no of steps to rotate the array";
    cin >> k;
    rotate(v, size, k);
    for (int i = 0; i < size; i++)
    {
        cout << v[i]<<" ";
    }
}