#include <bits/stdc++.h>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i=0 ;i<n ;i++){
            a[i] = 2*i+1;
        }
        for(int i=0 ;i<n ;i++) std::cout << a[i] << " ";
        std::cout << "\n";
}
}