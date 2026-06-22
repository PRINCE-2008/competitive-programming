#include <bits/stdc++.h>

using namespace std;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define ll long long
#define rep(i,a,b) for(int i = a ; i < b ; i++)

void solution(){
    int n, k ;
    cin >> n >> k ;
    ll dp[k+1][n+1] ={0};
    rep(i,0,n+1) {
        dp[1][i] = 1 ;
    }
    for(int i = 2 ; i <= k ; i++)
    {
        for(int j = 1 ; j <=n ; j++)
        {   
            // dp[i][j] = 0 ;
            for(int l = j ; l <= n ; l+= j)
            {
                dp[i][l] = (dp[i-1][j]% 1000000007 + dp[i][l]% 1000000007) % 1000000007 ;
            
            
        }
    }
    }
    ll ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        ans = (ans% 1000000007 + dp[k][i]% 1000000007) % 1000000007 ;
    }
    cout << ans << "\n";

}
int main(){
    FastIO();
    solution();
}