#include<iostream>
#include<vector>
using namespace std;
void pascaltri(vector<vector<int>> &v,int n){
    for(int i=1;i<=n;i++){
        v.push_back(vector<int> (i,1));
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<i;j++){
            v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
    }
}
int main(){
    //int n;
    //cin>>n;
    vector<vector<int>> v;
    // pascaltri(v,n);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<v[i][j];

    //     }
    //     cout<<endl;
    // }
    auto a=v.begin();
    cout<<a;
}
