#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , x ;
    cin >> n >> x ;
    for(int i = 0 ; i < n ; i++){
        if(i == x){
            continue;
        }
        cout << i << ' ';
    }
    if(x < n){
        cout << x << "\n";
    } else {
        cout << "\n";
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