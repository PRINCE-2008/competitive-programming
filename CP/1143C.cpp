#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;   
    vector<int> a[n+1];
    for(int i = 0 ; i < n+1 ; i++){
        a[i].clear();
    }
    int root = -1 ;
    bool respect[n-1] = {0};
    for(int i = 1 ; i <= n ;  i++){
        int x;
        bool res ;
        cin >> x >> res ;
        if(x == -1){
            root = i ;
            continue ;
        }
        a[x].push_back(i);
        respect[i] = res ;
    }
    vector<int> ans ;
    
    stack<int> s ;
    s.push(root);
    while(!s.empty()){
        bool childRespect = false ;
        int u = s.top();
        s.pop();
        for(auto child : a[u]){
            if(!respect[child]){
                childRespect = true ;
            }
            s.push(child);
        }
        if(!childRespect && respect[u]){
            ans.push_back(u);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0){
        cout << -1 << "\n";
    } else {
        for(int i = 0 ; i < ans.size() ; i++){
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}