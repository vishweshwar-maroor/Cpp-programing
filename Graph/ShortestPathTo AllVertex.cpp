/*
Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E weighted directed edges represented by a 2D array edges[][], where edges[i] = [u, v, wt] denotes a directed edge from vertex u to vertex v with weight wt, find the shortest distance from the source vertex 0 to every other vertex.

Return an array of size V, where the i-th element represents the shortest distance from the source vertex 0 to vertex i. If a vertex is not reachable from the source, return -1 for that vertex.

Input: V = 4, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
*/
#include <iostream>

#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void bfs(vector<vector<pair<int, int>>> &adj, int node, vector<int> &parent, vector<bool> &visited)
    {
        queue<int> q;
        q.push(node);
        parent[node] = -1;
        while (!q.empty())
        {
            int front = q.front();
            visited[front] = true;
            q.pop();
            for (auto a : adj[front])
            {
                if (!visited[a.first])
                {
                    q.push(a.first);
                    if (parent[a.first] == -2)
                    {
                        parent[a.first] = front;
                    }
                }
            }
        }
    }
    void makeAns(vector<int> &ans, vector<int> &parent, vector<vector<pair<int, int>>> &adj, int end)
    {
        int temp = end;
        while (1)
        {
            if (parent[temp] == -2)
            {
                ans[temp] = -1;
                break;
            }
            if (temp == 0)
            {
                break;
            }
            int child = temp;
            temp = parent[temp];
            int weight;
            for (auto a : adj[temp])
            {
                if (a.first == child)
                {
                    weight = a.second;
                    break;
                }
            }
            ans[end] += weight;
        }
    }
    vector<int> shortestPath(int V, vector<vector<int>> &edges)
    {
        // code here
        int n = V;
        vector<vector<pair<int, int>>> adj(n);
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> parent(n, -2);
        for (auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            adj[u].push_back({v, a[3]});
        }

        bfs(adj, 0, parent, visited);
        vector<int> ans(n, 0);
        ans[0] = 0;
        for (int i = 1; i < n; i++)
        {
            makeAns(ans, parent, adj, i);
        }
        return ans;
    }
};
