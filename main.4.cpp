#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Graph
{
    int V;                              // number of vertices
    vector<tuple<int, int, int>> edges; // (weight, u, v)
public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, u, v});
    }

    void KruskalMST()
    {
        sort(edges.begin(), edges.end()); // sort edges by weight
        DisjointSet ds(V);

        int totalWeight = 0;
        cout << "Edges in MST:" << endl;

        for (const auto &p : edges)
        {
            int w = std::get<0>(p);
            int u = std::get<1>(p);
            int v = std::get<2>(p);
            if (ds.find(u) != ds.find(v))
            {
                cout << u << " - " << v << " (weight: " << w << ")" << endl;
                totalWeight += w;
                ds.unite(u, v);
            }
        }

        cout << "Total weight = " << totalWeight << endl;
    }
};

int main()
{
    Graph g(4); // Example: 4 nodes

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 5);

    g.KruskalMST();

    return 0;
}
