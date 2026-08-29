#include <iostream>

#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &adj, int node, vector<int> &parent, vector<bool> &visited)
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
            if (!visited[a])
            {
                q.push(a);
                if (parent[a] == -2)
                {
                    parent[a] = front;
                }
            }
        }
    }
}
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // Write your code here
    vector<vector<int>> adj(n + 1);
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -2);
    for (auto a : edges)
    {
        int u = a.first;
        int v = a.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj, s, parent, visited);

    int temp = t;
    vector<int> v;
    while (1)
    {
        if (temp == s)
        {
            v.push_back(temp);
            break;
        }
        v.push_back(temp);
        temp = parent[temp];
    }
    reverse(v.begin(), v.end());
    // for(auto a:v){
    //     cout<<a;
    // }
    return v;
}