#include <bits/stdc++.h>

void solution(){
    int n ;
    std::cin >> n;
     int x = 0;
    for(int i = 0 ; i < n ; i++){
       int temp ;
       std::cin >> temp ;
       x =std::max(x, temp); 
        
    }
    // std::cout << x << "\n";
    std::cout << (x==100? "YES\n" : "NO\n");
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