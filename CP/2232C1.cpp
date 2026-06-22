#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    // dp[j] stores the max people we can seat using exactly j tables.
    // Initialize with -1 to represent unreachable states.
    vector<int> dp(x + 1, -1);
    dp[0] = 0; 

    for (char c : u) {
        // Carry over previous states (simulating skipping the current person)
        vector<int> next_dp = dp; 
        
        for (int j = 0; j <= x; ++j) {
            if (dp[j] == -1) continue;

            // Option 1: Start a new table (Introverts and Ambiverts)
            if ((c == 'I' || c == 'A') && j < x) {
                next_dp[j + 1] = max(next_dp[j + 1], dp[j] + 1);
            }

            // Option 2: Join an existing open table (Extroverts and Ambiverts)
            // A table has room if total seated < total capacity of open tables
            if ((c == 'E' || c == 'A') && dp[j] < j * s) {
                next_dp[j] = max(next_dp[j], dp[j] + 1);
            }
        }
        dp = next_dp; // Update states for the next person
    }

    // The answer is the maximum value achieved across any number of open tables
    int ans = 0;
    for (int j = 0; j <= x; ++j) {
        ans = max(ans, dp[j]);
    }
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}