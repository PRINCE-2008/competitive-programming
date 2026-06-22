#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i= 0 ; i<n ; i++){
            std::cin >> v[i];
    }
 
    std::vector<ll> ans(n);
    ans[0] = v[0];
    ll sum = v[0];
    for(int i = 1; i<n;i++){
        sum += v[i];
        ans[i] = std::min(ll(ans[i-1]),sum/(i+1));
    }
    bool flag = true;
    for(int i=0 ; i<n ;i++){
        std::cout << ans[i] << " ";
    }
    std::cout <<  "\n";
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