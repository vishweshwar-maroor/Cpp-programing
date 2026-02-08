#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> v){
    vector<int> u;
    for(int i=v.size()-1;i>=0;i--){
        u.push_back(v[i]);
    }
    for (int i = 0; i <u.size() ; i++)
    {
       
        cout<< u[i]<<" ";
    }
    
}
int main(){
    int n;
    cout << "number of elements in array :";
    cin >> n;
    vector<int> arr(n);
    cout << "put elements of array";
    for (int i = 0; i < n; i++)
    {
       
        cin >> arr[i];
    }
    cout<<endl;
    reverse(arr);
  

    

}