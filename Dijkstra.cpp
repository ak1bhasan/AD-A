#include<iostream>
#include<vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 100000
void addEdge(vector<pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void shortestPath(vector<pair<int, int> > adj[], int V, int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > >pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto x:adj[u])
        {
            int v=x.first;
            int weight=x.second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    printf("Vertex Distance from Source\n");
    for(int i=0;i<V;++i)
        printf("%d \t\t %d\n",i,dist[i]);

}
int main()
{
    int V=4;
    vector<pair<int,int>>adj[V];
    addEdge(adj,0,1,4);
     addEdge(adj,0,2,2);
      addEdge(adj,0,3,5);
       addEdge(adj,2,3,1);
       shortestPath(adj,V,0);
       return 0;
}





