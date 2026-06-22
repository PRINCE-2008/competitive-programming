#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    ll n;
    ll t;
    std::cin >> n >> t ;
    if(n==t){
        std::cout << "0\n" ;
        return;
    }
    int ans =0 ;
    while(n!=1 && n>t){
        if(n%2==1){
            ans ++;
            if((n+1)/2==t || (n-1)/2 == t){
                std::cout << ans << '\n' ;
                return;
            }
             n = (((n+1)/2)%2==1) ? (n+1)/2 : (n-1)/2 ;
            // std::cout << n << "\n";
        }
        else {
            ans += 1;
            if(n/2 == t) {
                std:: cout << ans << '\n';
                return;
            }
            else n = n/2 ;
        }
        
    }

    std::cout << -1 << '\n' ;
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

//In this question is desined in this way that you are a person who want to eat exactly k apples and you have n apples in a box 
// but you don't want to count the apples one by one while eating them so you have a magical box which dived apples in the box 
// into two parts one part has floor of n/2 apple and other part has ceiling of n/2 apples and magical box takes one minute to divide 
// and you have to tell minimum time box will take to give you exactly k apples if box will not be able to give you k apples 
// then print -1.z