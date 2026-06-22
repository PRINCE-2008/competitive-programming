#include <bits/stdc++.h>

void solution(){
    int n ;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i =0 ; i < n ; i++){
        std::cin >> arr[i];
    }
    int countOnes = 0;
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        if(arr[i] == 1 ) countOnes++;
        else{
            ans += arr[i];
            if(countOnes > 0 ){
                countOnes=0;
            }
        }
    }
    if(countOnes>0) ans += 1;
    std::cout << ans   << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >>t;
    while(t--){
        solution();
    }
    
}