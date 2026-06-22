#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    std::map<int,int> m = {{0,0}, {1,0}, {2,0}};
    for(int i= 0 ; i<n ; i++){
            int key ;
            std::cin>> key ;
            m[key]++;
    }
    int ans = m[0];
    ans+= std::min(m[1],m[2]);
    ans+= std::abs(m[1]-m[2])/3;
    std::cout << ans << '\n';
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