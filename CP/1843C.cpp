#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    ll n ;
    cin >> n ;
    ll ans = 0 ;
    while(n > 0){
        ans+= n ;
        n = n/2 ;
    }
    cout << ans << endl ;
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