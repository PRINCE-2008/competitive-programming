#include <bits/stdc++.h>
typedef long long ll ;

void solution(){
    int n ;
    std::cin >> n ;
    std::vector<ll> a(n) ;
    for(int i = 0 ; i < n ; i++ ) std::cin >> a[i] ;
    ll sum = 0;
    ll max = INT64_MIN;
    int prev = 0 ;
    for(int i = 0 ; i < n ; i++){
        if( i == 0 ){
              max = a[0] ;
              if(a[0]>0) prev = 1 ;
              else prev = -1 ;
        }
        else{
            if(a[i]*prev > 0 ) {
                max = std::max(max,a[i]) ;
            }else{
                prev = prev*-1 ;
                sum += max ;
                max = a[i] ;

            }   
        }
        if( i == n-1) sum += max;
    }
    std::cout << sum << '\n' ;
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t ;
    std::cin >> t ;
    while( t-- ){
        solution();
    }
}