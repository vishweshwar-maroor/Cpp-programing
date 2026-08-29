/*Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

E is the number of edges present in graph G.
Note :
The Graph may not be connected i.e there may exist multiple components in a graph.*/

#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
void DFS(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &temp){
    visited[node]=true;
    temp.push_back(node);
    for(auto a: adj[node]){
        if(!visited[a]){
            visited[a]=true;
           DFS(a,adj,visited,temp);
        }
    }
    
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<bool> visited(V,false);
    vector<vector<int>> ans;
    vector<vector<int>> adj(V);
    for(auto a:edges){
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    //bool flag = true;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> temp;
            DFS(i,adj,visited,temp);
           
                ans.push_back(temp);
            
        }
    }
    // ans.pop_back();
    // for(auto a:ans){
    //     for(auto b :a){
    //         cout<<b;
    //     }
    //     cout<<endl;
    // }
    // cout <<endl;
    
       return ans;

}

