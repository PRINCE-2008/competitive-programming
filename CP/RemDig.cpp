#include <bits/stdc++.h>

using namespace std;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

int maxDigit(int n){
    int maxd = 0 ;
    while(n > 0){
        maxd = max(maxd,n%10) ;
        n /= 10;
    }
    return maxd;
}

void solution(){
    int n ;
    cin >> n ;
    int ans = 0 ;
    while(n != 0){
        n = n - maxDigit(n) ;
        ans ++;
    }
    cout << ans << '\n' ;
}

int main(){
    FastIO();
    solution();
}