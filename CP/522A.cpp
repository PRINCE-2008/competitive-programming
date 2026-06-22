#include <bits/stdc++.h>
#include <cctype>
using namespace std;

const int MAXN = 200 + 5;

vector<int> adj[MAXN];
int max_depth[MAXN];

void dfs(int node , int parent){
    max_depth[node] = 0 ;
    for(int neighbor : adj[node]){
        if(neighbor != parent){
            dfs(neighbor, node);
            max_depth[node] = max(max_depth[node], max_depth[neighbor] + 1);
        }
    }
}

void solution(){
    int n ;
    cin >> n ;
    for(int i = 0 ; i <= n+1 ; i++){
        adj[i].clear();
    }
    map<string, int> m;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        string a, b, c;
        cin >> a >> b >> c;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        if(m.find(c) == m.end()){
            m[c] = count++;
        }
        if(m.find(a) == m.end()){
            m[a] = count++;
        }
        adj[m[c]].push_back(m[a]);
        adj[m[a]].push_back(m[c]);
    }
    dfs(0, -1);
    int ans = max_depth[0] + 1 ;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}