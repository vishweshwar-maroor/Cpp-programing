/*
You are given three integers n
, k
, and m
.

We call an array a
 of length n
, consisting of positive integers, good if the minimum length of a non-empty subarray∗
 of a
 whose sum is divisible by m
 equals k
.

Formally, an array a
 is good if the following conditions hold:

there exist integers l
 and r
 such that 1≤l≤r≤n
, r−l+1=k
, and ∑i=lrai
 is divisible by m
;
there do not exist integers l
 and r
 such that 1≤l≤r≤n
, r−l+1<k
, and ∑i=lrai
 is divisible by m
.*/
#include<iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

// Speed optimization macros
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Type aliases for brevity
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

// Constants


// Core logic for each test case
string solve() {
    // Write your solution here
    int n,k,m;
    cin>>n>>k>>m;
    vi arr(n);
    vi cummarr(n);
    int data_in;
    for(int i=0;i<n;i++){
        cin>>data_in;
        arr[i]=data_in;
        if(i==0)cummarr[i]=data_in;
        else{
            cummarr[i]=cummarr[i-1]+data_in;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+k-1;j<n;j++){
            int sum=cummarr[j]-cummarr[i];
            if(sum%m==0) return "yes";

        }
    }
    return "no";

    
}

int main() {
    // Optimize standard I/O operations for speed
    fast_io;

    // Handle multiple test cases (standard for Codeforces)
    int t = 1;
    cin >> t; 
    while (t--) {
        string str =solve();
        cout<<str;
    }

    return 0;
}
