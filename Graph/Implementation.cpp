#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>> adj;


    void addEdge(T u,T v, bool directed){
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);
    }
    void printList(){
        for(auto a: adj){
            cout<<a.first<<"->";
            for(auto b: a.second){
                cout<<b<<",";
            }
            cout<<endl;
        }
        
    }
};
int main(){
    int n,m;
    cout<<"put number of nodes and  edges";
    cin >>n>>m;
    Graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printList();
}