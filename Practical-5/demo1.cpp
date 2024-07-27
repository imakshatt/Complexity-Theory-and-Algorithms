#include <bits/stdc++.h>
using namespace std;

class disjointset{
    vector<int> rank, parent;
public:
    //initializing two arrays rank and parent
    disjointset(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    //unioin
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return;
        //here i connect the smaller rank vertext to higher rank vertext
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    int kruskal(int V, multimap<int, pair<int, int>> &edges)
    {
        disjointset ds(V);
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
                ds.unionByRank(u, v);
                selectedEdges.push_back(make_tuple(u, v, wt));
            }
        }

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
    int mstWt = obj.kruskal(Vertex, edges);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << mstWt << endl;
    return 0;
}
