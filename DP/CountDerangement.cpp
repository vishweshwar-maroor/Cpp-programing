/*
Problem statement
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.

Note:
The answer could be very large, output answer %(10 ^ 9 + 7).
*/



#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7;
long long int solveSpace(int n){
    //basecase
    
    long long int prev2=0,prev1=1;
    for(long long int i=3;i<=n;i++){
        long long int curr=(i-1)*(prev1+prev2);
        curr=curr%MOD;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;

}
long long int solve(int n,vector<long long int> &dp){
    //basecase
    
    if(n==1) return 0;
    if(n==2)  return 1;
    
    if(dp[n]!=-1) return dp[n];
    long long int ans=(n-1)*(solve(n-1,dp)+solve(n-2,dp));
    ans=ans%MOD;
    dp[n]=ans;
    return ans;

}
long long int countDerangements(int n) {

    // Write your code here.
    vector<long long int> dp(n+1,-1);
    return solve(n,dp)%MOD;
}

int main()