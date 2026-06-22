#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    ll n , x , y ;      cin >> n >> x >> y ;
    ll ans = 0 ;
    vector<ll> money(n);
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        cin >> money[i];
        sum += (money[i]/x)*y;
    }
    // cout << sum << "\n";
    for(int i = 0 ; i < n ; i++){
        ans = max(ans, money[i]+ sum - (money[i]/x)*y);
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