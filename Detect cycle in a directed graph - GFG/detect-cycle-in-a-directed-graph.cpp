//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool helper(int node, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        
        bool ret = false;
        for(auto i : adj[node]){
            if(vis[i] == 1) return true;
            else if(vis[i] == 0) {
                ret = ret || helper(i,vis,adj);
            }
        }
        
        vis[node] = 2;
        return ret;
    }

public:
    // Function to detect a cycle in an undirected graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0; // Initialize the vis array
        }

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0 && helper(i, vis, adj)) return true;
        }
        // for(int i = 1;i<V;i++) cout<<vis[i]<<" ";
        // cout<<endl;
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