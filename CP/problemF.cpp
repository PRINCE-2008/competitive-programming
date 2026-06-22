#include <bits/stdc++.h>

void solution(){
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
       std::cin >> v[i];
    }
    
    std::sort(v.begin(), v.end());
    
    // If k == 0, we need a value >= 1 that is strictly less than all elements
    if (k == 0) {
        if (v[0] == 1) {
            std::cout << -1 << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    } else {
        // If k > 0, the answer must be at least v[k-1]
        int ans = v[k - 1];
        
        // Check if there are more than k elements <= ans
        if (k < n && v[k] == ans) {
            std::cout << -1 << "\n";
        } else {
            std::cout << ans << "\n";
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
   solution();
}