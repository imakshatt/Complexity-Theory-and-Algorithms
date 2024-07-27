#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int spanningTree()
    {
        vector<pair<int, pair<int, int>>> edges;

        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;

        vector<tuple<int, int, int>> selectedEdges;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
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
            // tuple reference i have to create to extract
            tie(u, v, wt) = edge;
            cout << "{" << u << "-" << v << ", Weight: " << wt << "}" << endl;
        }

        return mstWt;
    }
};

int main()
{

    int V = 7;
    //{u,v,weight}

    
    Solution obj;
    cout << "MST for : "
         << "{{0,1,4}, {0,7,8}, {1,7,11}, {1,2,8}, {7,8,7}, {6,7,1}, {6,8,6}, {2,8,2}, {5,6,2}, {2,5,4}, {2,3,7}, {3,5,14}, {3,4,9}, {4,5,10}}" << endl;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}
