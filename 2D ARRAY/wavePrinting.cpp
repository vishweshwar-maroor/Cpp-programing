#include <iostream>
using namespace std;
int MAX=100;
void wave(int arr[][10],int row,int col)
{   int z=0;
    
   for(int i=0;i<col;){
    int j;
        if(z==0){ 
            for(j=0;j<row;j++){
                cout<<arr[i][j]<<" ";
                if(j==row-1){
                    z=1;
                    i++;
                }

            }
        }
        if(z==1){
            for( j=row-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
                if(j==0){
                    z=0;
                    i++;
                }
            }
        }
        if(i==col-1&&((j==0)||(j==row-1))){
            return;
        }
   }
}
int main()
{
    cout << "put number of rows and column for matrix";
    int row, coulmn;
    cin >> row >> coulmn;
    int arr[row][10];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < coulmn; j++)
        {
            cin >> arr[i][j];
        }
    }
    wave(arr,row,coulmn);
}