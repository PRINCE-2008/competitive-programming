#include <bits/stdc++.h>



void solution(){
    int n ; std::cin >> n ;
    std::vector<int> a(n) ; for(int i = 0 ; i < n ; i++) std::cin >> a[i] ;
    int ans = a[0] ; 
    int min = a[0] ;
    for(int i = 1 ; i < n ; i++){
        min = std::min(min, a[i]) ;
        ans += min ;
    }
    std::cout << ans << "\n" ;
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