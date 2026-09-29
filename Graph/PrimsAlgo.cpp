/*
Problem statement
You are given an undirected connected weighted graph having ?N? nodes numbered from 1 to 'N'. A matrix ?E? of size M x 2 is given which represents the ?M? edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.
*/

#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int findNext(vector<int> &key,vector<bool> &mst,int n,int &mini){
    int ans;
    for(int i=1;i<=n;i++){
        if(mst[i]==false&&key[i]<mini){
            ans=i;
            mini=key[i];
        }
    }
    return ans;
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<vector<vector<int>>> adj(n+1);
    for(auto a:g){
        int u=a.first.first;
        int v=a.first.second;
        int w=a.second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);
    key[1]=0;
    parent[1]=-1;
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        int next=findNext(key,mst,n,mini);
        mst[next]=true;
        for(auto a:adj[next]){
            int u=a[0];
            int w=a[1];
            if(key[u]>w && mst[u]==false){
                key[u]=w;
                parent[u]=next;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}



/*
using heap


 
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;
int findNext(vector<int> &key,vector<bool> &mst,int n,int &mini){
    int ans;
    for(int i=1;i<=n;i++){
        if(mst[i]==false&&key[i]<mini){
            ans=i;
            mini=key[i];
        }
    }
    return ans;
}
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<vector<vector<int>>> adj(n+1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto a:g){
        int u=a.first.first;
        int v=a.first.second;
        int w=a.second;
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);
    key[1]=0;
    parent[1]=-1;
    int src =1;
    pq.push({0,src});
    while(!pq.empty()){
        // int mini=INT_MAX;
        // int next=findNext(key,mst,n,mini);
        int next=pq.top().second;
        pq.pop();
        mst[next]=true;
        for(auto a:adj[next]){
            int u=a[0];
            int w=a[1];
            if(key[u]>w && mst[u]==false){
                key[u]=w;
                parent[u]=next;
                pq.push({key[u],u});
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}

*/