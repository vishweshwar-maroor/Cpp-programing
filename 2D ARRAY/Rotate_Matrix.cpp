#include <iostream>
#include<algorithm>
using namespace std;
int MAX=100;
void Rotate90(int arr[][100],int n)
{ int marker=0;
    while( marker<(n/2)){
        for(int i=marker;i<n-1-marker;i++){
            swap(arr[marker][marker+i],arr[marker+i][marker+n-1]);
            swap(arr[marker][marker+i],arr[marker+n-1][marker+n-1-i]);
            swap(arr[marker][marker+i],arr[marker+n-1-i][marker]);
        }
        marker++;
    }
}
int main()
{
    cout << "put number of rows for matrix";
    int n;
    cin >>n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    Rotate90(arr,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
        cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }
}