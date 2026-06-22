#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> inter(n);
    for(int i=0 ; i<n ;i++){
        std::cin >> inter[i].first >> inter[i].second;
    }
    std::vector<int> perm(n);
    for(int i=0 ;i<n ;i++) perm[i] = i;
    
    for(int i=0 ;i<n ;i++) std::cout << perm[i]+1 << " ";
    std::cout << "\n";
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--){
        solution();
    }

}