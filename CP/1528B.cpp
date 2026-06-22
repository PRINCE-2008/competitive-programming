#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solution(){
    int n;
    cin  >> n ;
    vector<pair<int,int>> l_r(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> l_r[i].first >> l_r[i].second ;

    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < n-1 ; i++){
        int u , v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 0 ;
    if(n>2){
        for(int i = 1 ; i <= n ; i++){
            if(adj[i].size() > 1){
                root = i ;
                break ;
            }
        }
    }else {
        root = 1 ;
    }
    vector<int> beauty(n+1,0);
    vector<ll> dp(n+1,0);
    stack<int> st;
    st.push(root);
    vector<int> parent(n+1,0);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        int temp1 = 0 ;
        int temp2 = 0 ;
        if(node == root){
            for(int child : adj[node]){
                temp1 += max({
                    abs(l_r[node].first - l_r[child].first) ,
                    abs(l_r[node].first - l_r[child].second )
                });
                temp2 += max({
                    abs(l_r[node].second - l_r[child].first) ,
                    abs(l_r[node].second - l_r[child].second )
                });
                st.push(child);
                parent[child] = node ;
            }
            if(temp1 > temp2){
                beauty[node] = l_r[node].first ;
                for(int child : adj[node]){
                    if(abs(l_r[node].first - l_r[child].first) > abs(l_r[node].first - l_r[child].second)){
                        beauty[child] = l_r[child].first ;
                    } else {
                        beauty[child] = l_r[child].second ;
                    }
                }
            } else {
                beauty[node] = l_r[node].second ;
                for(int child : adj[node]){
                    if(abs(l_r[node].second - l_r[child].first) > abs(l_r[node].second - l_r[child].second)){
                        beauty[child] = l_r[child].first ;
                    } else {
                        beauty[child] = l_r[child].second ;
                    }
                }
            }
            dp[node] = max(temp1,temp2) ;
        }else{
            for(int child : adj[node]){
                if(child == parent[node]) continue ;
                dp[node] += max({
                    abs(beauty[node] - l_r[child].first) ,
                    abs(beauty[node] - l_r[child].second )
                });
                if(abs(beauty[node] - l_r[child].first) > abs(beauty[node] - l_r[child].second)){
                    beauty[child] = l_r[child].first ;
                } else {
                    beauty[child] = l_r[child].second ;
                }
                st.push(child);
            }
            dp[node] += dp[parent[node]] ;
        }
    }
    cout    << dp[root] << "\n" ;
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