#include <bits/stdc++.h>

void solution(){
    std::vector<int> arr(7);
    int max = INT_MIN;
    for(int i = 0 ; i < 7 ; i++){
        std::cin >> arr[i] ;
        max = std::max(max,arr[i]);
    }
    int sum = 0 ;
    for(int i = 0 ; i < 7 ; i++){
        
            sum += -arr[i];
        
    }
    std::cout << 2*max +sum << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        solution();
    }
}