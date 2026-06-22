#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    int n;
    cin >> n ;
    vector<vector<ll>> v(2,vector<ll>(n));
    for(int i = 0 ; i < 2 ; i++) for(int j = 0 ; j < n ; j++) cin >> v[i][j];
    ll dp1prev , dp2prev , dp3prev , dp1curr , dp2curr , dp3curr ;
    dp1prev = v[0][0];
    dp2prev = v[1][0];
    dp3prev = 0;
    for(int i = 1 ; i < n ; i++){
        dp1curr = max(dp2prev+v[0][i], max(dp3prev+v[0][i], v[0][i]));
        dp2curr = max(dp1prev+v[1][i], max(dp3prev+v[1][i], v[1][i]));
        dp3curr = max(dp1prev, dp2prev);
        dp1prev = dp1curr;
        dp2prev = dp2curr;
        dp3prev = dp3curr;
    }
    cout << max(dp1prev, max(dp2prev, dp3prev)) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}