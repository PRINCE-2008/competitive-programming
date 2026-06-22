#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin >>  n;
    char v[n][n];
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) cin >> v[i][j];

    if(v[0][0] == '*' || v[n-1][n-1] == '*'){
        cout << 0 << "\n";
        return ;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1 ;
    for(int i = 1 ; i < n ;i++){
        if(v[i][0] == '*'){
            dp[i][0] = 0 ;
            break ;
        }
        dp[i][0] = dp[i-1][0] ;
    }
    for(int i = 1 ; i < n ;i++){
        if(v[0][i] == '*'){
            dp[0][i] = 0 ;
            break ;
        }
        dp[0][i] = dp[0][i-1] ;
    }
    for(int i = 1 ; i < n ;i++){
        for(int j = 1 ; j < n ; j++){
            if(v[i][j] == '*'){
                dp[i][j] = 0 ;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])  ;
            }
            if(dp[i][j] >= 1000000007){
                dp[i][j] -= 1000000007 ;
            }
        }
    }

    cout << dp[n-1][n-1] << endl ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}