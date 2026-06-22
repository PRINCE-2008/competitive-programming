#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k ;
    cin >> n >> k ;
    vector<int> coins(n);
    for(int i = 0 ; i < n ; i++) cin >> coins[i];
    int dp[k+1] = {0};
    dp[0] = 1 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = coins[i] ; j<= k ; j++){
            if(dp[j-coins[i]] >= 0)
            dp[j] = dp[j] + dp[j-coins[i]] ;
            if(dp[j] >= 1000000007){
                dp[j] -= 1000000007 ;
            }
        }
    }
    cout << dp[k] << "\n" ;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}