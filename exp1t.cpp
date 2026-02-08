#include<iostream>
#include<vector>
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
    n=n-1;
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    long long int l1=queries[0][0]-1,r1=queries[0][1]-1,l2=queries[1][0]-1,r2=queries[1][1]-1;
    //for query 1;
    
    long long int querylength1=r1-l1+1;
    
    long long int querysize1=querylength1/n;
    
    int ans1=sum*querysize1;
    
    //extras
    int extraR1=r1%n;
    
    int extraL1=l1%n;
    // cout<<extraL1<<extraR1;
    long long int extrasumL1=0;
    for(int i=extraL1;i<n;i++){
        extrasumL1+=arr[i];
    }
    cout<<extrasumL1<<endl;
    long long int extrasumR1=0;
    for(int i=0;i<=extraR1;i++){
        extrasumR1+=arr[i];
    }
    cout<<extrasumR1<<endl;
    ans1=ans1+extrasumR1+extrasumL1;
    //for query 2

    
    long long int  querylength2=r2-l2+1;
    long long int querysize2=querylength2/n;
     int ans2=sum*querysize2;
    //extras
    int extraR2=r2%n;
    int extraL2=n-l2%n;
    long long int extrasumL2=0;
    for(int i=extraL2;i<=n;i++){
        extrasumL2+=arr[i];
    }
    long long  int extrasumR2=0;
    for(int i=0;i<=extraR2;i++){
        extrasumR2+=arr[i];
    }
    ans2=ans2+extrasumR2+extrasumL2;

    vector<int> v={ans1,ans2};
    return v;
}
int main(){
    vector<int> arr={1,2,3};
    int n=3;
    vector<vector<long long>> queries={{1,3},{1,5}};
    int q=2;
    vector<int> v=sumInRanges(arr,n,queries,q);
    cout<<v[0]<<endl<<v[1];

}