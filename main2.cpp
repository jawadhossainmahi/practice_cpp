#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class graph
{
private:
    int number_of_nodes;
    vector<vector<int>> adj;

public:
    graph(int n)
    {
        this->number_of_nodes = n;
        adj.assign(n, vector<int>(n, 0)); // properly initialize matrix
    }

    void addEdges(int source, int destination)
    {
        adj[source][destination] = 1;
        adj[destination][source] = 1; // undirected
    }

    void print()
    {
        for (int i = 0; i < number_of_nodes; i++)
        {
            for (int j = 0; j < number_of_nodes; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void bfs(int start)
    {
        vector<bool> visited(this->number_of_nodes, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from node " << start << ": ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < number_of_nodes; i++)
            {
                if (this->adj[node][i] == 1 && visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start)
    {
        vector<bool> visited(this->number_of_nodes, false);
        stack<int> s;

        visited[start] = true;
        s.push(start);

        cout << "DFS traversal starting from node " << start << ": ";
        while (!s.empty())
        {
            int node = s.top();
            cout << node << " ";
            s.pop();
            for (int i = 0; i < this->number_of_nodes; i++)
            {
                if (this->adj[node][i] == 1 && visited[i] == false)
                {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        cout << endl;
    }
};

class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node(int value)
    {
        this->data = value;
    }
};

class bst
{
public:
    node *root = NULL;

    node *insert(node *Node, int value)
    {
        if (Node == NULL)
        {
            return new node(value);
        }

        if (value < Node->data)
        {
            Node->left = insert(Node->left, value);
        }
        else if (value > Node->data)
        {
            Node->right = insert(Node->right, value);
        }

        return Node;
    }

    void inOrder(node *Node)
    {
        if (Node == NULL)
            return;
        inOrder(Node->left);
        cout << Node->data << " ";
        inOrder(Node->right);
    }

    void preOrder(node *Node)
    {
        if (Node == NULL)
        {
            return;
        }
        cout << Node->data << " ";
        inOrder(Node->left);
        inOrder(Node->right);
    }
    void postOrder(node *Node)
    {
        if (Node == NULL)
        {
            return;
        }
        inOrder(Node->left);
        inOrder(Node->right);
        cout << Node->data << " ";
    }
};
void file()
{
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
}

int main()
{
    file();
    int n;
    cin >> n;

    bst bst;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        root = bst.insert(root, value);
    }

    cout << " root is " << root->data;
    cout << "inorder: ";
    bst.inOrder(root);
    cout << "\npre order: ";
    bst.preOrder(root);
    cout << "\npost order: ";
    bst.postOrder(root);

    return 0;
}
