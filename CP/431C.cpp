#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

void solution(){
    int n , k , d ;
    cin >> n >> k >> d ;
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    dp[0][0] = 1 ;
    dp[0][1] = 1 ;
    for(int i = 1; i < n+1 ; i++){
        for(int weight = 1 ; weight <= k ; weight++){
            if(i - weight >= 0){
                dp[i][0] = (dp[i][0] + dp[i-weight][0]) % MOD ;
                if(weight < d){
                    dp[i][1] = (dp[i][1] + dp[i-weight][1]) % MOD ;
                }
            }
        }
    }
    cout << (dp[n][0] - dp[n][1] + MOD) % MOD << "\n" ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}