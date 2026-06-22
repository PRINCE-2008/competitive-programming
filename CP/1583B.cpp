#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , m;
    cin >> n >> m ;
    vector<bool> isRestricted(n+1,false);
    for(int i = 0 ; i < m ; i++){
        int a , b , c ;
        cin >> a >> b >> c ;
        isRestricted[b] = true ;
    }
    int center = 0 ;
    for(int i = 1  ; i <= n ; i++){
        if(!isRestricted[i]){
            center = i ;
            break ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(i != center){
            cout << center << ' ' << i << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}