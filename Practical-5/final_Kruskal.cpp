#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU != rootV)
        {
            if (size[rootU] < size[rootV])
                swap(rootU, rootV);

            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, multimap<int, pair<int, int>> &edges)
    {
        DisjointSet ds(V);
        int mstWt = 0;

        vector<tuple<int, int, int>> selectedEdges;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
                selectedEdges.push_back(make_tuple(u, v, wt));
            }
        }

        // Print the selected edges with their weights
        cout << "Selected edges for the MST:" << endl;
        for (auto edge : selectedEdges)
        {
            int u, v, wt;
            tie(u, v, wt) = edge;
            cout << "{" << u << "-" << v << ", Weight: " << wt << "}" << endl;
        }

        return mstWt;
    }
};

int main()
{
    int Vertex;
    cout << "Enter the total number of vertex: ";
    cin >> Vertex;
    int numEdges;
    cout << endl;
    cout << "Enter the number of Edges: ";
    cin >> numEdges;
    multimap<int, pair<int, int>> edges;

    vector<int> u(numEdges);
    vector<int> v(numEdges);
    vector<int> weight(numEdges);

    for (int i = 0; i < numEdges; i++)
    {
        cout << "Enter U: ";
        cin >> u[i];
        cout << "Enter V: ";
        cin >> v[i];
        cout << "Enter w: ";
        cin >> weight[i];
        edges.insert({weight[i], {u[i], v[i]}});
        cout << "---------------------------" << endl;
    }

    Solution obj;
    cout << "MST for : " << endl;
    for(auto it : edges){
        cout << "[w:" << it.first << ", {u:" << it.second.first << "," << it.second.second << "}]";
        cout << endl;
    }
    int mstWt = obj.spanningTree(numEdges, edges);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << mstWt << endl;
    return 0;
}
