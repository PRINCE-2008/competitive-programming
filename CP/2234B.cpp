#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void solution(){
    ll n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++) cout << i << ' ';
    for(int i = 1 ; i <= n ; i++) cout << i << ' ';
    cout << n << ' ';
    for(int i = 1 ; i < n ; i++) cout << i << ' ';
    for(int i = 1 ; i <= n ; i++) cout << i << ' ';
    cout << "\n";
    
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