#include <bits/stdc++.h>
typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<ll> a(n);
        for (int i=0 ;i<n ;i++) std::cin >> a[i];
        ll maxVal = *std::max_element(a.begin(), a.end());
        ll max2nd = -1;
        for (int i=0 ;i<n ;i++){
            if(a[i] != maxVal) max2nd = std::max(max2nd, a[i]);
        }
        if(max2nd == -1) std::cout << "0\n";
        else
        std::cout << max2nd%maxVal << "\n";
    }
}