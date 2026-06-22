#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n; 
    cin >> n;
    bool possible = true;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        
        int odd_i = i;
        while(odd_i > 0 && odd_i % 2 == 0) odd_i /= 2;
        
        int odd_x = x;
        while(odd_x > 0 && odd_x % 2 == 0) odd_x /= 2;
        
        if(odd_x != odd_i) {
            possible = false;
        }
    }
    if(possible){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--){
            solution();
        }
    }
    return 0;
}
