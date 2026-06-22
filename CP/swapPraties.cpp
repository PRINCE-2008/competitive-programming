#include <bits/stdc++.h>

bool canBeSorted(std::vector<int> &arr){
    int even=0;
    int odd=0;
    for(int i=0 ;i<arr.size() ;i++){
        if(arr[i]%2 ==0){
            if(arr[i] < even) return 0;
            even = arr[i];
        }
        else{
            if(arr[i] < odd) return 0;
            odd = arr[i];
        }
    }
    return 1;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >>t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int i=0 ;i<n ;i++) std::cin >> arr[i];
        if(canBeSorted(arr)) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
}