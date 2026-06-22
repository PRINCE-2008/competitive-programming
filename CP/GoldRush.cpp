#include <bits/stdc++.h>
using namespace std;

// void solution(){
//     int n , m ;
//     cin >> n >> m ;

//     if(m > n ){
//         cout << "NO\n";
//         return ;
//     }
//     vector<int> dp(n+1,0);
//     for(int i = 1 ; i <= n ; i++){
//         if(i % 3 == 0){
//             dp[i] = dp[i/3 * 2] + dp[i/3] ;
//         }else dp[i] = 1 ;
//     }

//     if(dp[n] >= m){
//         cout << "YES\n";
//     } else {
//         cout << "NO\n";
//     }
// }

bool find( int n  , int m ){
    vector<bool> dp(n+1,0);
    for(int i = m ; i <= n ; i++){
        if(i == m){
            dp[i] = 1 ;
        }
        else if(i % 3 == 0){
            dp[i] = dp[i/3 * 2] || dp[i/3] ;
        } 
    }
    return dp[n] ;
}

void solution(){
    int n , m ;
    cin >> n >> m ;

    vector<bool> dp(n+1,0);
    for(int i = m ; i <= n ; i++){
        if(i == m){
            dp[i] = 1 ;
        }
        else if(i % 3 == 0){
            dp[i] = dp[i/3 * 2] || dp[i/3] ;
        } 
    }
    if(dp[n]){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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