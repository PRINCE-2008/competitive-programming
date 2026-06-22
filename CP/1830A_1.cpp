#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Adjacency list storing pairs of {neighbor, edge_index}
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        // Store the 1-based index 'i' of the edge
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<int> readings(n + 1, 0);
    vector<int> id_drawn(n + 1, 0);
    
    // Base case setup for the root vertex
    readings[1] = 1;
    id_drawn[1] = 0; 

    // We will use a standard DFS stack approach instead of recursion 
    // to avoid stack overflow issues on deep trees
    vector<int> stack;
    stack.push_back(1);
    
    int max_readings = 1;

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int edge_idx = edge.second;

            // If v is not yet visited (readings[v] == 0)
            if (readings[v] == 0) {
                // If the new edge appears AFTER the edge that drew 'u', it's drawn in the same reading
                if (edge_idx > id_drawn[u]) {
                    readings[v] = readings[u];
                } 
                // If it appears BEFORE, we need a new reading
                else {
                    readings[v] = readings[u] + 1;
                }
                
                id_drawn[v] = edge_idx;
                max_readings = max(max_readings, readings[v]);
                stack.push_back(v);
            }
        }
    }

    cout << max_readings << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}