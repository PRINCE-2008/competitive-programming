#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int depth[MAXN];
int siz[MAXN];

void dfs(int node ,int parent){
    siz[node] = 1 ;
    for(int child : adj[node]){
        if(child != parent){
            depth[child] = depth[node] + 1 ;
            dfs(child,node);
            siz[node] += siz[child];
        }
    }
}

void solution(){
    int n , k;
    cin >> n >> k ;
    for(int i = 0 ; i <= n ; i++){
        adj[i].clear();
    }
    for(int i = 0 ; i < n-1 ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    vector<int> res(n);
    for(int i = 1; i <= n ; i++){
        res[i-1] = depth[i] - (siz[i]-1) ;
    }
    //sort in descending order
   sort(res.begin(),res.end(),greater<int>());
    long long ans = 0 ;
    ans = accumulate(res.begin(),res.begin() + k,0LL);
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}