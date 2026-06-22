#include <bits/stdc++.h>

void solution(){
    int n;
    int k;
    std:: cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        std::cin >> v[i];
    }
    int sum = accumulate(v.begin(),v.end(),0);
    if(sum%2==1 || k*n % 2 == 0){
        std::cout << "YES\n";
    }else{
        std::cout << "NO\n";
    }
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