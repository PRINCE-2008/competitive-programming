#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for(int i = 0; i < n-1 ; i++){
        if(a[n-1-i]>0){
            if(a[n-2-i]+a[n-1-i]>0){
                a[n-2-i] += a[n-1-i];
            }
        }
    }
    int countPos = 0;
    for(int i = 0 ; i < n ;i++){
        if(a[i] > 0){
            countPos++;
        }
    }
    std::cout << countPos << "\n";
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