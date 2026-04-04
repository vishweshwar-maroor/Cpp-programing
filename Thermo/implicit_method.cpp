#include<iostream>
#include<vector>
using namespace std;
int temp(vector<int> &v,int index){
    if(index==0) return v[index];
    if(index==v.size()-1){
        return v[index];
    }
    if(v[index]!=0) return v[index];
    int temp1=temp(v,index-1);
    int temp2=temp(v,index+1);
    int tempi=(temp1+temp2)/2;
    v[index]=tempi;
    return tempi;
}
vector<int> Area(int size){
    vector<int> v(size+1);

}
int main(){
    vector<int> v(10,300);
    v[0]=500;
    v[9]=1000;
    int temp1=temp(v,1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

}