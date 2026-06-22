#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];

ll leaf_count[MAXN];

void dfs(int node, int parent) {
    leaf_count[node] = 0;
    bool is_leaf = true;

    for(int neighbor : adj[node]) {
        if(neighbor != parent) {
            is_leaf = false;
            dfs(neighbor, node);
            leaf_count[node] += leaf_count[neighbor];
        }
    }
    if(is_leaf) {
        leaf_count[node] = 1;
    }
}

void solution() {
    int n;
    cin >> n ;
    for(int i = 0 ; i <= n ; i++){
        adj[i].clear();
    }
    for(int i = 0 ; i < n-1 ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    
    int q ;
    cin >> q ;
    for(int i = 0 ; i < q ; i++){
        int u , v ;
        cin >> u >> v ;
        cout << leaf_count[u] * leaf_count[v] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}