/*
Problem statement
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
*/

#include <bits/stdc++.h>
using namespace std;
int maxi = INT_MIN;
void solve(vector<int> &nums, int i, int sum)
{
    // base case
    if (i >= nums.size())
    {
        maxi = max(maxi, sum);
        return;
    }

    // include
    solve(nums, i + 2, sum + nums[i]);

    // exclude
    solve(nums, i + 1, sum);
    return;
}
int solveMem(vector<int> &nums, int i, vector<int> &dp)
{
    
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
        return nums[0];
    if (dp[i] != -1)
        return dp[i];

    int inc = solveMem(nums, i - 2, dp) + nums[i];

    int exc = solveMem(nums, i - 1, dp);

    dp[i] = max(inc, exc);
    return dp[i];
}

int solveTab(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int inc=dp[i-2]+nums[i];
        int exc=dp[i-1];
        dp[i]=max(inc,exc);
    }
    return dp[n-1]
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    // maxi=INT_MIN;
    // solve(nums,0,0);

    // return maxi;
    int n = nums.size();
    vector<int> dp(n - 1, -1);
    int ans=solveMem(nums,n-1,dp);
    return ans;
}