/*
Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E weighted directed edges represented by a 2D array edges[][], where edges[i] = [u, v, wt] denotes a directed edge from vertex u to vertex v with weight wt, find the shortest distance from the source vertex 0 to every other vertex.

Return an array of size V, where the i-th element represents the shortest distance from the source vertex 0 to vertex i. If a vertex is not reachable from the source, return -1 for that vertex.

Input: V = 4, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto a : adj[node])
        {
            if (!visited[a])
            {
                dfs(a, adj, st, visited);
            }
        }
        st.push(node);
    }
    void topoSort(vector<vector<int>> &adj, vector<int> &topoSortResult, vector<bool> &visited, int V)
    {
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, st, visited);
            }
        }
        for (!st.empty())
        {
            topoSortResult.push_back(st.top());
            st.pop();
        }
    }
    void makeAdj(vector<vector<int>> &adj, vector<vector<int>> &edges, int V, unordered_map<pair<int, int>,int> &weight)
    {
        for (auto a : edges)
        {
            weight.insert({a[0], a[1]}, a[2]);
            adj[a[0]].push_back([a[1]]);
        }
    }
    vector<int> shortestPath(int V, vector<vector<int>> &edges)
    {
        unordered_map<pair<int, int>, , int> weight;
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);
        makeAdj(adj,edges,V,weight);
        vector<int> topoSortResult;
        topoSort(adj, topoSortResult, visited, V);
        vector<int> ans(V, INT_MAX);
        ans[0] = 0;
        for (auto a : topoSortResult)
        {
            if (ans[a] == INT_MAX)
            {
                continue;
            }
            else
            {
                for (auto b : adj[a])
                {
                    if (ans[b] > ans[a] + weight[{a, b}])
                    {
                        ans[b] = ans[a] + weight[{a, b}];
                    }
                }
            }
        }
        return ans;
    }
};
