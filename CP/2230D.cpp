#include <bits/stdc++.h>

void solution(){
    int n ;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for(int i = 0 ; i < n ; i++){
        std::cin >> a[i];
    }
    for(int i = 0 ; i < n ;i++){
        std::cin >> b[i];
    }
    int ans = 0 ;
    int count = 1 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
             if((a[j] != b[j]) && (a[j] == count || b[j] == count)){
                count = 1;
                break;
            
            }else {
                if(a[j] == b[j] && a[j] == count){
                    count ++;
                }
                ans ++;
            }
        }
        count = 1;
        // std::cout << ans << " ";
    }
    std::cout << ans << std::endl;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--){
        solution();
    }
}