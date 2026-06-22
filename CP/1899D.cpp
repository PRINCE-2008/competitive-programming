#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <cmath>

void solution(){
    int n;
    cin >> n;
    int value;
    map<int,int> m;
    for(int i = 0 ; i < n ; i++){
        cin >> value;
        m[value]++;
    }
    ll ans = 0 ;
    for(auto [key,value] : m){
        ans += (ll(value) * ll(value-1))/2 ;
    }
    if(m.count(1) && m.count(2)){
        ans += ll(m[1]) * ll(m[2]) ;
    }
    cout << ans << "\n";
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