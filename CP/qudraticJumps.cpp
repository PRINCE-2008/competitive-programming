#include<bits/stdc++.h>
typedef long long ll;

void solution(){
    int n ,q ;
    std::cin>> n>>q;
    std::set<int> s;
    // perfect squres less than n
    for(int i=1 ;i*i<n ;i++) s.insert(i*i);
    std::vector<std::vector<int>> graphset(n,std::vector<int>(n,0));
    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<i ;j++){
            if(s.count(i-j)){
                graphset[i][j] = 1;
                graphset[j][i] = 1;
            }
        }
    }
    std::vector<std::vector<int>> pairs(q,std::vector<int>(2));
    for(int i=0 ;i<q ;i++){
        std::cin >> pairs[i][0] >> pairs[i][1];
    }
    // shortest path between pairs of vertices in graphset
    for(auto &it : pairs){
        int u = it[0];
        int v = it[1];
        std::vector<int> dist(q,INT_MAX);
        std::queue<int> qu;
        qu.push(u);
        dist[u] = 0;
        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            for(int i=0 ;i<n ;i++){
                if(graphset[curr][i] && dist[i] == INT_MAX){
                    dist[i] = dist[curr]+1;
                    qu.push(i);
                }
            }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        
    }
}