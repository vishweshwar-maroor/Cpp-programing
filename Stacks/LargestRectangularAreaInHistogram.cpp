#include<iostream>
#include<stack>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class pair{
    public:
    int f;
    int s;
    pair(int f,int s){
        this->f=f;
        this->s=s;
    }
};
vector<int> nextSmallest(vector<int>& heights){
    int size=heights.size();
    vector<int> ans[size];
    
    stack<int> s;
    s.push(-1);
    for(int i=size-1;i>=0;i--){
        if(s.top()!=-1&&heights[i]>heights[s.top()]){
            ans[i]=s.top();
            s.push(heights[i]);
            
            
        }
    }
}
int largestRectangleArea(vector<int>& heights) {
    stack<pair<int>> st;


}
int main(){
    vector<int> heights = {2,5,5,6,2,3};
    cout << "Largest Rectangular Area in Histogram: " << largestRectangleArea(heights) << endl;
    return 0;

    

}