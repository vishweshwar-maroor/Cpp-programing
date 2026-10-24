/*
Problem statement
You are given an integer ‘N’ denoting the length of the rod. You need to determine the maximum number of segments you can make of this rod provided that each segment should be of the length 'X', 'Y', or 'Z'.

*/


#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int solveMem(int n, int x, int y, int z,vector<int> &dp){
	if(n==0) {
		
		return 0;
	}
	if(n<0) return INT_MIN;
	if(dp[n]!=-1) return dp[n];
	int a,b,c;

	a=solveMem(n-x,x,y,z,dp);

	b=solveMem(n-y,x,y,z,dp);
	
	c=solveMem(n-z,x,y,z,dp);

	dp[n]=max(a,max(b,c))+1;
	return dp[n];
		

}
int solveTab(int n, int x, int y, int z){
	vector<int> dp(n+1,-1);
	dp[0]=0;
	for(int i=1;i<=n;i++){
        if(i-x>=0) dp[i]=max(dp[i],dp[i-x]+1);
        if(i-y>=0) dp[i]=max(dp[i],dp[i-y]+1);
        if(i-z>=0) dp[i]=max(dp[i],dp[i-z]+1);        
    }
    return dp[n];
		

}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int> dp(n+1,Int_MIN);
	int ans=solveMem(n,x,y,z,dp);
	if(ans>0) return ans;
	else return 0;

}
int main(){

}