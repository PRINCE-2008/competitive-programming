#include <bits/stdc++.h>
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

using namespace std;

void solution(){
    int n ;
    scanf("%d",&n);
    int a[n] = {0};
    for(int i = 0 ; i < n ; i++) scanf("%d" , &a[i]);
    bool rest[n] = {0};
    int ans[n] = {0};
    for(int i = 0 ;i < n ; i++){
        if( i == 0 )
        {
            if(a[i] == 0)
            {
                ans[i] = 1 ; 
                rest[i] = 1 ;
            }
            continue;
        }
        if(a[i] != 3)
        {
            if(a[i] == 0)
            {
                rest[i] = 1 ;
                ans[i] = ans[i-1] + 1 ;
            }else if(a[i] == a[i-1] && rest[i-1] ==0)
            {
                rest[i] = 1 ;
                ans[i] = ans[i-1] + 1 ;
            
            }else if(a[i] != a[i-1] || (a[i] == a[i-1] && rest[i-1] == 1))
            {
                ans[i] = ans[i-1] ;
            }
        }else
        {   
            if(a[i-1] == 1 && rest[i-1] == 0){
                a[i] = 2;
            }
            if(a[i-1] == 2 && rest[i-1] == 0){
                a[i] = 1;
            }
            ans[i] = ans[i-1] ;
        }
    }
    printf("%d\n", ans[n-1]);
}

int main(){
    FastIO();
    solution();

}