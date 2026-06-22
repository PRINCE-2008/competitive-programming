#include <bits/stdc++.h>

void solution(){
    int n ;
    std::cin >> n;
    std::string s ;
    std::cin >> s ;
    std::reverse(s.begin(), s.end());
    s.insert(s.begin(), '\n');

    int ans = 0 ;
    char curr ;
    int k ;
    for(int i = 1 ; i < n + 1 ;i++){
        curr = s[  i ];
        for( int j = i - 1 ; j >= 0 ;  j--){
            if( s[j] == curr || s[j] == '\n'){
                k = i - j ;
                break;
            }
        }
        ans += k ;
    }
    std::cout << ans << '\n' ;

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t ;
    std::cin >> t;
    while( t-- ){
        solution();
    }
}