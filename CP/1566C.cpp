#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n ;
    std::string a , b ;
    std:: cin >> a >> b ;
    int ans=0;
    for(int i = 0 ; i < n ; i++){
        if(a[i]=='1'&&b[i]=='1'){
            if(a[i+1] == '0' && b[ i + 1] == '0' ){
                ans += 2;
                i++;
            }
            else continue ;
        }
        else if( (a[i] == '1' && b[i] == '0') || ( a[i] == '0' && b[i] == '1')){
            ans += 2;
        }
        else if(a[i] == '0' && b[i] == '0'){
            if(a[i+1] == '1' && b[ i + 1] == '1' ){
                ans += 2;
                i++;
            }
            else ans++;
        }
    }
    std::cout<< ans << '\n';
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