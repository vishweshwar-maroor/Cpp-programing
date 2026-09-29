#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    //memoisation
    int solve(vector<int> &cost, vector<int> &dp, int n)
    {
        if (n == 1 || n == 0)
        {
            return cost[n];
        }
        if (dp[n]!=-1){
            return dp[n];
        }
        else{
            dp[n] = min(solve(cost,dp, n - 1), solve(cost,dp, n - 2)) + cost[n];
        return dp[n];
        }

            
    }
    //tabulation
    int solve1(vector<int> &cost, vector<int> &dp, int n)
    {
        if (n == 1 || n == 0)
        {
            return cost[n];
        }
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[n];

            
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n ,- 1);
        int ans = min(solve1(cost,dp, n - 1), solve1(cost,dp, n - 2));
        return ans;
    }
};

int main()