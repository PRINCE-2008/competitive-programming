#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    ll n;
    ll a;
    ll b;
    std::cin >> n >> a >> b;
    ll ans=0;
    if(3*a > b){
        ll t = n/3;
        ans = b*t;
        n = n%3;
        if(n==2){
            if(2*a > b) ans +=b;
            else ans += 2*a;
        }else if(n==1){
            if(a>b) ans +=b;
            else ans += a;
        }
        std::cout << ans  << '\n';
        return;
    }else{
        ans += a*n;
        std::cout << ans  << '\n';
        return;
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