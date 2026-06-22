#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define pb push_back
#define pop pop_back


const int MAXN = 1000 + 1;
vector<int> adj[MAXN];
bool leaf[MAXN];
int leaf_child_count[MAXN];

void dfs(int node, int parent) {
    leaf[node] = true;
    for(int neighbor : adj[node]) {
        if(neighbor != parent) {
            leaf[node] = false;
            dfs(neighbor, node);
            if(leaf[neighbor]) {
                leaf_child_count[node]++;
            }
        }
    }
}

void solution() {
    int n;
    cin >> n;
    for(int i = 0 ; i <= n ; i++){
        adj[i].clear();
    }
    for(int i = 1 ; i <= n-1 ; i++){
        int x ;
        cin >> x;
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }
    dfs(1, -1);
    
    for(int i = 1 ; i <= n ; i++){
        if(!leaf[i] && leaf_child_count[i] < 3){
            cout << "No\n";
            return;

        }
    }
    cout << "Yes\n";
}

int main(){
    FastIO();
    solution();
    return 0;
}