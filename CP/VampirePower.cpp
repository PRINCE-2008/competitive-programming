#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n ;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    
    vector<bool> seen(256,false);

    seen[0] = true;
    int prefix_xor = 0 ;
    int max_xor = 0 ;

    for(int i = 0 ; i < n ; i++){
        prefix_xor ^= v[i];
        for(int j = 0 ; j < 256 ; j++){
            if(seen[j]){
                max_xor = max(max_xor, prefix_xor ^ j);
            }
        }
        seen[prefix_xor] = true;
    }
    cout << max_xor << "\n";
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