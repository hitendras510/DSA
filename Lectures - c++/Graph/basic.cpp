#include <iostream>
#include <vector>
#include <list>
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

int main()
{
    Graph g(5); // no. of verticies

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printList();
    return 0;
}