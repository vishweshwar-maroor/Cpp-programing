#include<iostream>
#include<vector>
using namespace std;
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}


int main(){
    cout<<"put number of stairs ";
    int stairs;
    
    cin>>stairs;
    int n=stairs;
    vector<int> pair(2,0);
    vector<vector<int>> doublet;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if((i*1+j*2)==stairs){
                pair[0]=i,pair[1]=j;
                doublet.push_back(pair);
            }
        }
    }
    int row=doublet.size();
    int ways=0;
    for(int i=0;i<row;i++){
        ways=ways+(nCr(doublet[i][0]+doublet[i][1],doublet[i][1]));
    }
    cout<<ways;
    
    


}   