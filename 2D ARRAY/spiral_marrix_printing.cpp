#include <iostream>
using namespace std;
int MAX=100;
void spiral(int arr[][100],int row,int col)
{
    //int i = 0, j = 0;
    int p = 0, q = col - 1, r = 0, s = row - 1;
    while (p<=q&&r<=s)
    {
        if (p<=q&&r<=s)
        {
            for (int j = p; j <= q; j++)
            {
                cout << arr[r][j];
            }
            // j--;
            // i++;

            r++;
        }
        if (p<=q&&r<=s)
        {
            for (int i = r; i <= s; i++)
            {
                cout << arr[i][q];
            }
            // i--;
            // j--;
            q--;
        }
        if (p<=q&&r<=s)
        {
            for (int j = q; j >= p; j--)
            {
                cout << arr[s][j];
            }
            // j++;
            // i--;
            
            s--;
        }
        if (p<=q&&r<=s)
        {
            for (int i = s; i >= r; i--)
            {
                cout << arr[i][p];
            }
            // i++;
            // j++;
            p++;
        }
    }
}
int main()
{
    cout << "put number of rows and column for matrix";
    int row, coulmn;
    cin >> row >> coulmn;
    int arr[100][100];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coulmn; j++)
        {
            cin >> arr[i][j];
        }
    }
    spiral(arr,row,coulmn);
}