#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include <climits>
using namespace std;

class Edge{
    public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};
void dijkstra(int src,vector<vector<Edge>> g,int V){
vector<int> dist(V, INT_MAX);
dist[src] = 0;

//pair-> (dist[u],u)
//priority_queue<pair<int,int>> pq; (normal priority queue but, we need min heap)

priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;  //min-heap
pq.push({0,src});

while(pq.size()>0){
    int u = pq.top().second;
    pq.pop();

    for(Edge e:g[u]){
        if(dist[e.v]>dist[u]+e.wt){
            dist[e.v] = dist[u]+e.wt;
            pq.push({dist[e.v],e.v});
        }
    }
}
for(int i=0;i<V;i++){
    cout<<dist[i]<<" ";
}
cout<<endl;
}


int main(){
    int V=6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,3));
    g[1].push_back(Edge(3,6));

    g[2].push_back(Edge(3,7));

    g[3].push_back(Edge(4,5));

    g[4].push_back(Edge(5,1));
    g[4].push_back(Edge(5,2));

    dijkstra(0,g,V);
    return 0;
}