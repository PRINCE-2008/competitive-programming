#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    ll a,b;
    std::cin >> a >> b ;
    ll n = b/a;
    if(n == 2) std::cout << "NO\n";
    else std::cout << "YES\n";
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