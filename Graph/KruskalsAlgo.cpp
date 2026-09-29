/*
You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices (numbered from 0 to V-1) and E number of edges.

Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
*/

#include<bits/stdc++.h>
#include<queue>
using namespace std;


int findParent(vector<int> &parent,int node){
    if(parent[node]==node){
        return node;
    }

    parent[node]=findParent(parent,parent[node]);
    return parent[node];
    
}
void unionSet(vector<int> &parent,vector<int> &rank,int u,int v ){
    v=parent[v];
    u=parent[u];
    
    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }

}
bool cmp(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
    vector<int> parent(n);
    vector<int> rank(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    sort(edges.begin(),edges.end(),cmp);
    
    // for(auto a:edges){
    //     for(auto b:a){
    //         cout<<b;
    //     }
    //     cout<<endl;
    // }
    //kkuskals algo;
    int minweight=0;
    for(auto a: edges){
        int u=a[0];
        int v=a[1];
        int wt=a[2];
        int uparent=findParent(parent,u);
        int vparent=findParent(parent,v);
        //cout<<uparent<<vparent<<endl;
        if(uparent!=vparent){
            minweight+=wt;
            unionSet(parent,rank,uparent,vparent);
        }
        
    }
    return minweight;

  
}