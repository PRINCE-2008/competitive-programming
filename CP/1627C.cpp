#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    int n;
    cin >> n ;
    vector<pair<int,int>> adj[n+1];
    for(int i = 0 ; i < n ; i++){
        adj[i].clear();
    }
    for(int i = 1 ; i <= n-1 ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int primeEdge[n];
    int end_node = 1 ;
    for(int i = 1 ; i <= n ; i++){
        if(adj[i].size() >= 3){
            cout << -1 << "\n";
            return ;
        }
        if(adj[i].size() == 1){
            end_node = i ;
        }
    }
    primeEdge[adj[end_node][0].second] = 2 ;
    int current_color = 1 ;
    int current_node = end_node ;
    int parent_node = 0 ;
    while(true){
        int next_node = -1 ;
        for(auto edge : adj[current_node]){
            if(edge.first != parent_node){
                next_node = edge.first ;
                if(current_color == 1){
                    primeEdge[edge.second] = 3 ;
                    current_color = 0 ;
                } else {
                    primeEdge[edge.second] = 2 ;
                    current_color = 1 ;
                }
            }
        }
        if(next_node == -1) break ;
        parent_node = current_node ;
        current_node = next_node ;
    }
    for(int i = 1 ; i <= n-1 ; i++){
        cout << primeEdge[i] << ' ';
    }
    cout << "\n";
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