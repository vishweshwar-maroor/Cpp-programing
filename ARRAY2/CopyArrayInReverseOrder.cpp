#include <iostream>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void reverse(vector<int>& v,int size){
    for (int i = 0; i < size / 2; i++)
    {
        swap(v[i], v[v.size() - 1 - i]);
    }

}
int main()
{
    vector<int> v = {1,2,3,4};
    int size = v.size();
    reverse(v,size); //reverse
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}