#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void file()
{
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
}

class graph
{
private:
    int number_of_node;
    vector<vector<pair<int, int>>> adj;

public:
    graph(int n)
    {
        this->number_of_node = n;
        adj.assign(n, {});
    }

    void addEdge(int src, int destination, int weight)
    {
        adj[src].push_back({destination, weight});
        adj[destination].push_back({src, weight});
    }

    void printGraph()
    {
        for (int i = 0; i < number_of_node; i++)
        {
            cout << i << " -> ";
            for (const auto &p : this->adj[i])
            {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }

        void primsMST(int start = 0)
    {
        vector<int> key(number_of_node, INT_MAX);  // store minimum edge weight to connect
        vector<int> parent(number_of_node, -1);    // store parent node in MST
        vector<bool> inMST(number_of_node, false); // check if node is already in MST

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;
            inMST[u] = true;

            for (const auto &p : adj[u])
            {
                int v = p.first, weight = p.second;
                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        int totalWeight = 0;
        cout << "Edges in MST:" << endl;
        for (int i = 1; i < number_of_node; i++)
        {
            cout << parent[i] << " - " << i << " (weight: " << key[i] << ")" << endl;
            totalWeight += key[i];
        }
        cout << "Total weight = " << totalWeight << endl;
    }
};

int main()
{
    file();
    int n, number_of_edges;
    cin >> n >> number_of_edges;
    graph gh(n);
    for (int i = 0; i < number_of_edges; i++) // fixed bug here
    {
        int src, destination, value;
        cin >> src >> destination >> value;
        gh.addEdge(src, destination, value);
    }

    cout << "Graph adjacency list:" << endl;
    gh.printGraph();

    cout << endl;
    gh.primsMST(); // run Prim’s algorithm
}
