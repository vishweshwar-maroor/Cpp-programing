/*You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

Example :

In the below graph, there exists a cycle between vertex 1, 2 and 3. */
#include <bits/stdc++.h>
bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited, unordered_map<int,list<int>> &adjList)
{

    visited[src] = 1;

    // recursive call for each adjacent node

    for (auto i : adjList[src])
    {

        if (!visited[i])
        {

            bool cycleDetected = isCyclicDFS(i, src, visited, adjList);

            if (cycleDetected)

                return true;
        }

        else if (i != parent)
        {

            // cycle Detected

            return true;
        }
    }

    return false;
}
using namespace std;
bool bfs(vector<vector<int>> &adj, int node, vector<bool> &visited, unordered_map<int, int> &parent)
{
    queue<int> q;
    parent[node] = node;
    q.push(node);
    while (!q.empty())
    {
        int front = q.front();
        /// cout <<front<<" ";
        q.pop();
        // when we pop we visit
        visited[front] = true;
        // for(auto a:visited) {cout<<a<<"";}

        for (auto a : adj[front])
        {
            if (visited[a] == false)
            {
                q.push(a);

                parent[a] = front;
            }
            else
            {
                // check if parent of front is a or not
                if (parent[front] != a)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n + 1);

    unordered_map<int, int> parent; // child,parent
    for (auto a : edges)
    {
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            bool flag = bfs(adj, i, visited, parent);
            if (flag == true)
                return false;
        }
    }
    return true;
}

int main()
{
}