/*You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

Example:*/
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF INT_MAX

using namespace std;

struct Compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

void AdjList(vector<vector<vector<int>>> &adj, vector<vector<int>> &vec)
{
    for (auto a : vec)
    {
        int u = a[0];
        int v = a[1];
        int w = a[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Fix adjacency list type to store pairs of {neighbor, weight}
    vector<vector<vector<int>>> adj(vertices);
    vector<int> ans(vertices, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap; // {distance, node}
    
    AdjList(adj, vec);
    
    // Corrected 'src' to 'source'
    ans[source] = 0;
    minHeap.push({0, source});
    
    while (!minHeap.empty())
    {
        int d = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();
        
        // If a shorter path to u has already been processed, skip
        if (d > ans[u]) continue;

        for (auto a : adj[u])
        {
            int v = a[0];
            int weight = a[1];
            
            if (ans[u] + weight < ans[v])
            {
                ans[v] = ans[u] + weight;
                minHeap.push({ans[v], v});
            }
        }
    }
    return ans;
}