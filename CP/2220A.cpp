#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    std::vector<int > arr(n);
    for(int i = 0 ; i< n ;i++){
        std::cin >> arr[i];
    }
    std::sort(arr.begin(),arr.end(),[](int a, int b){
        return a > b;
    });
    for(int i = 0 ; i< n ; i++){
        if(arr[i] == arr[i+1]){
            std::cout << "-1\n";
            return;
        }
    }
    for(int i = 0 ; i < n ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
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