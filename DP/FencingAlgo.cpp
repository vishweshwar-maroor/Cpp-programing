
/*Problem statement
Ninja has given a fence, and he gave a task to paint this fence. The fence has 'N' posts, and Ninja has 'K' colors. Ninja wants to paint the fence so that not more than two adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task, so he asked for your help.

Your task is to find the number of ways Ninja can paint the fence. Print the answer modulo 10^9 + 7.

Example:
Input: 'N' = 3, 'K' = 2
Output: 6

Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations.

110
001
101
100
010
011

*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * 1ll * (b % MOD)) % MOD;
}
int solve(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    vector<long int> samedp(n + 1, -1);
    vector<long int> diffdp(n + 1, -1);
    vector<long int> totaldp(n + 1, -1);
    samedp[2] = k;
    diffdp[2] = k * (k - 1);
    totaldp[2] = samedp[2] + diffdp[2];
    for (int i = 3; i <= n; i++)
    {
        samedp[i] = diffdp[i - 1];
        samedp[i] %= MOD;
        diffdp[i] = totaldp[i - 1] * (k - 1);
        diffdp[i] %= MOD;
        totaldp[i] = samedp[i] + diffdp[i];
        totaldp[i] %= MOD;
    }
    return totaldp[n];
}
int solveSpace(int n, int k)
{
    if (n == 1)
        return k;
    long int prevSame = k, prevDiff = k * (k - 1), prevTotal = prevDiff + prevSame;
    for (int i = 3; i <= n; i++)
    {
        long int currSame = prevDiff;
        currSame %= MOD;
        long int currDiff = prevTotal * (k - 1);
        currDiff %= MOD;
        long int currTotal = currDiff + currSame;
        currTotal %= MOD;
        prevDiff = currDiff;
        prevSame = currSame;
        prevTotal = currTotal;
    }
    return prevTotal;
}
int solveSpace2(int n, int k)
{
    /*
    currSame=(k-1)solve(n-2)
    currDiff=(k-1)solve(n-1)
    solve(n)-> gives totaldp[n];
    */

    if (n == 1)
        return k;
    if (n == 2)
    {
        return add(k, mul(k, k - 1));
    }
    int prev2 = k, prev1 = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        int curr = add(mul(k - 1, prev1), mul(k - 1, prev2));
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int numberOfWays(int n, int k)
{
    // Write your code here.
    return solveSpace(n, k);
}
