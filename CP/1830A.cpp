#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;

void solution(){
    int n;
    cin >> n ;
    vector<vector<pair<int, int>>> adj(n+1);


    for(int i = 1 ; i <= n-1 ; i++){
        int u , v;
        cin >> u >> v ;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }


    vector<int> reading(n+1, 0);
    vector<int> id(n+1, 0);
    id[1] = 0;
    reading[1] = 1;

    vector<int> stac;
    stac.push_back(1);
    int maxReading = 1 ;

    while(!stac.empty()){
        int u = stac.back();
        stac.pop_back();

        for(auto edge : adj[u]){
            int v = edge.first;
            int edgeIdx = edge.second;

            if(reading[v] == 0){
                if(edgeIdx > id[u]){
                    reading[v] = reading[u];
                } else {
                    reading[v] = reading[u] + 1;
                }
            
            id[v] = edgeIdx;
            maxReading = max(maxReading, reading[v]);
            stac.push_back(v);
            }
        }
    }
    cout << maxReading << "\n";
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