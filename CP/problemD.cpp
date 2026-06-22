#include <bits/stdc++.h>

void solution(){
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        std::cin >> v[i];
    }
    int sum = 0;
    
    // 1. Initialize the first window of size k
    for(int i = 0; i < k; i++){
        sum += v[i];
    }
    
    int ans = sum; // min_sum
    int j = 0;     // index of the min window
    
    // 2. Slide the window across the rest of the array
    for(int i = k; i < n; i++){
        sum = sum - v[i-k] + v[i];
        
        // 3. Update minimum strictly (important for returning the FIRST instance)
        if(sum < ans){
            ans = sum;
            j = i - k + 1;
        }
    }
    
    std::cout << j + 1 << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solution();
}