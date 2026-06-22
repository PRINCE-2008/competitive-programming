#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n;
    long long t; // use long long to prevent overflow
    std::cin >> n >> t;
    std::vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        std::cin >> v[i];
    }
    
    int ans = 0;
    ll sum = 0;
    int left = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum > t){
            while(sum > t && left <= i){
                sum -= v[left];
                left++;
            }
        }
        ans = std::max(ans, i - left + 1);
}
    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solution();
}