#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

void solution(){
    int n , k;
    cin >> n >> k ;
    vector<int> d(n);
    for(int i = 0 ; i < n ; i++) cin >> d[i];
    vector<int> dp(k+1,0);
    dp[0] = 0 ;
    for(int i = 1 ; i <= k ; i++){
        dp[i] = INT_MAX ;
        for(auto x : d){
            if(i-x >= 0 && dp[i-x] != -1){
                dp[i] = min(dp[i],dp[i-x]+1) ;
            }
            
        }
        if(dp[i] == INT_MAX){
            dp[i] = -1 ;
        }
    }
    cout << dp[k] << "\n" ;
}

int main(){
    FastIO();
    solution();
}