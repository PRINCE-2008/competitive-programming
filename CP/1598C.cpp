#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for ( int& i : a ) std::cin >> i;
    ll sum = 0;
    for (int i : a){
        sum += i;
    }
    
    // We need A + B = (2 * sum) / n
    // If 2 * sum is not perfectly divisible by n, no integer pair exists.
    if ((2 * sum) % n != 0) {
        std::cout << "0\n";
        return;
    }
    
    ll k = (2 * sum) / n;
    
    ll ans = 0;
    std::map<int, int> m;
    
    // Standard one-pass 2-sum approach is much safer and avoids edge cases.
    for(int i = 0 ; i < n ; i++){
        // If we have already seen elements that can pair with a[i] to sum to k,
        // add their count to the answer.
        if (m.count(k - a[i])) {
            ans += m[k - a[i]];
        }
        
        // Then add the current element to our map for future pairs.
        m[a[i]]++;
    }
    
    std::cout << ans << '\n' ;
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