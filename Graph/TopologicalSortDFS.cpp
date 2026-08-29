/*Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E directed edges represented by a 2D array edges[][], where edges[i] = [u, v] denotes a directed edge from vertex u to vertex v, return a topological ordering of all the vertices.

A topological ordering is a linear ordering of the vertices such that for every directed edge u -> v, vertex u appears before vertex v in the ordering.

Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<vector<int>> & adj,stack<int> & st,vector<bool> &visited){
        visited[node]=true;
        for(auto a: adj[node]){
            if(!visited[a]){
                dfs(a,adj,st,visited);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<bool> visited(V, false);
        stack<int> st;
        vector<vector<int>> adj(V);
        for (auto a : edges)
        {
            adj[a[0]].push_back(a[1]);
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i,adj,st,visited);
            }
        }
        vector<int> ans;
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};