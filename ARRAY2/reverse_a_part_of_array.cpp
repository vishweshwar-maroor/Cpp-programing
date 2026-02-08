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
void reverse(vector<int>& v,int size,int start,int end){
    for (int i = start,j=end; i<=j; i++,j--)
    {
        swap(v[i], v[j]);
    }

}
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    int size = v.size();
    cout<<"put index from where you want to reverse";
    int a;int b;
    cin>>a>>b;
    reverse(v,size,a,b); //reverse
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}