#include <bits/stdc++.h>
using namespace std;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
typedef long long ll;

void solution(){
    int n , x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for(int i = 0 ; i < n ; i++) cin >> prices[i];
    for(int i = 0 ; i < n ; i++) cin >> pages[i];

    vector<ll> dp(x+1,0);
    for(int i= 0 ; i < n ; i++){
        for(int j = x ; j >= prices[i] ; j--){
            dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]) ;
        }
    }
    
    cout << dp[x] << '\n';
}

int main(){
    FastIO();
    solution();
    return 0;
}