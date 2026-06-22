#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    map<int, ll> m;
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        
        m[v[i]-i] += v[i];
        ans = max(ans, m[v[i]-i]);
    }
    cout << ans << "\n";
   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}