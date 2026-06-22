#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n , k , z;
    cin >> n >> k >> z;
    vector<int> a(n+1 );
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    vector<vector<array<int, 2>>> dp(k + 1, vector<array<int, 2>>(z + 1, {-1, -1}));
    
    dp[0][0][0] = a[1];

    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j <= z ;j++){
            for(int flag = 0 ; flag <= 1 ; flag++){
                
                
                if(dp[i][j][flag] == -1) continue;
                
                int pos = 1 + i - 2*j ;

                if(pos < n){
                    dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][flag] + a[pos+1]);

                }
                if(pos > 1 && j < z && flag == 0){
                    dp[i+1][j+1][1] = max(dp[i+1][j+1][1], dp[i][j][flag] + a[pos-1]);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0 ; j <= z ; j++){
        ans = max({ans, dp[k][j][0], dp[k][j][1]});
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
// #include <bits/stdc++.h>
// using namespace std;

// void solution() {
//     int n, k, z;
//     cin >> n >> k >> z;
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     // dp[moves][lefts][last_was_left]
//     // Initialized to -1 to represent unvisited/impossible states
//     vector<vector<array<int, 2>>> dp(k + 1, vector<array<int, 2>>(z + 1, {-1, -1}));

//     // Base Case: 0 moves, 0 lefts, didn't just move left
//     dp[0][0][0] = a[1];

//     for (int i = 0; i < k; i++) {
//         for (int j = 0; j <= z; j++) {
//             for (int flag = 0; flag < 2; flag++) {
//                 // Skip unreachable states
//                 if (dp[i][j][flag] == -1) continue;

//                 // Calculate current position based on moves
//                 int pos = 1 + i - 2 * j;

//                 // 1. Try moving Right
//                 if (pos < n) {
//                     dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][flag] + a[pos + 1]);
//                 }

//                 // 2. Try moving Left
//                 // Valid if: not at start, have left moves remaining, AND last move wasn't left
//                 if (pos > 1 && j < z && flag == 0) {
//                     dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][flag] + a[pos - 1]);
//                 }
//             }
//         }
//     }

//     // The answer is the maximum score after exactly 'k' moves across any number of valid left moves
//     int ans = 0;
//     for (int j = 0; j <= z; j++) {
//         ans = max({ans, dp[k][j][0], dp[k][j][1]});
//     }
    
//     cout << ans << "\n";
// }

// int main() {
//     // Optimize standard I/O operations for performance
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while (t--) {
//         solution();
//     }
//     return 0;
// }