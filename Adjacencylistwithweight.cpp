// ###Whole code of weighted undirected graph, along with displaying the output:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // USING ADJACENCY LIST
    int n, m, u, v, w;
    cout << "Enter the number of nodes and edges for the graph: " << endl;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the edge to be included:" << endl;
        cin >> u >> v;
        cout << "Enter the weight of this edge:" << endl;
        cin >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Displaying the graph:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "-> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";
        }
        cout << endl;
    }
    return 0;
}
