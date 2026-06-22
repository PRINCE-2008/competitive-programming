#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , m , p , q ;
    cin >> n >> m >> p >> q ;
    int left = n%p ;
    if(left == 0){
        if(q*int(n/p) == m){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "YES\n";
    }
    return;
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