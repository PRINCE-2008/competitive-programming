#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p;
    
    // 1. The first element must always be the maximum value (all bits set)
    p.push_back((1 << n) - 1);
    
    // 2. Iterate over the position of the lowest 0-bit from highest to lowest
    for (int k = n - 1; k >= 0; --k) {
        
        // Number of variations for the higher bits
        int num_prefixes = 1 << (n - 1 - k); 
        
        // 3. Generate all combinations for this specific lowest 0-bit
        for (int P = 0; P < num_prefixes; ++P) {
            // Shift prefix past the 0-bit, and fill the lower k bits with 1s
            int val = (P << (k + 1)) | ((1 << k) - 1);
            p.push_back(val);
        }
    }
    
    // 4. Output the permutation
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << (i + 1 == p.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
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