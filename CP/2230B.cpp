#include <bits/stdc++.h>

void solution(){
    std::string s;
    std::cin >> s;
    int n = s.size();
    int ans =0 ;
    int two = 0 ;
    int odd = 0 ;
    for(char c : s){
        if(c == '4') ans ++;
        else {
            if(c == '2' && odd != 0){
                two ++;
                if( two >= odd){
                    ans += odd;
                    odd = 0 ;
                    two = 0;
                }
            }else if( c == '1' || c == '3' )odd++;
    }
}
    std::cout << ans + two << "\n";
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