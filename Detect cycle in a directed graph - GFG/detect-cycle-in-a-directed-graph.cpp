//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(int i, int parent, vector<bool> &vis, vector<bool> &dfsvis, vector<int> adj[]){
        vis[i] = true;
        dfsvis[i] = true;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(it, i, vis, dfsvis, adj))
                    return true;
            }else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[i] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
       vector<bool> vis(V, false);
       vector<bool> dfsvis(V, false);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, dfsvis, adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends