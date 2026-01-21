#include <iostream>
#include <vector>
#include <list>
#include<queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    public:

    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    // print vetrix value
    void printList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int neighnour : l[i])
            {
                cout << neighnour << " ";
            }
            cout << endl;
        }
    }
};
//bfs traversal 
void bfs(){
    queue<int> q;
    vector<bool> vis(V, false);

    q.push(0);
    vis[0] = true;

    while(q.size()>0){
        int u = q.front();
        q.pop();

        cout<<u<<" ";

        for(int v: l[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

//dfs traversal
void dfsHelper(int u, vector<bool> &visit){
    cout<< u << " ";
    visit[u] = true;

    for(int v: l[u]){
        if(!visit[v]){
            dfsHelper(v,visit);
        }
    }
}
void dfs() {
    int src =0;
    vector<bool> vis(V , false);

    dfsHelper(src,vis);
}

int main()
{
    Graph g(5); // no. of verticies

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);

    g.dfs();
    return 0;
}