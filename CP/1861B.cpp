#include <bits/stdc++.h>

void solution(){
    std::string a;
    std::string b;
    std:: cin >> a >> b ;
    int n = a.size();
    std :: vector<int> vec( n, -1 );
    for(int i = 0 ; i < n ; i++){
        if(a[i] == '0' && b[i] == '0') vec[i] = 0 ;
        if( a[i] == '1' && b[i] == '1') vec[i] = 1 ;
    }
    bool isOne = false ;
    if(vec[0] == -1 || vec[ n-1 ] == -1) {
        std :: cout << "NO\n" ;
        vec.clear();
        a.clear();
        b.clear();
        return;
    }else if(vec[0] == vec[n-1]) {
        std :: cout << "YES\n" ;
        vec.clear();
        a.clear();
        b.clear();
        return;
    }
    int val = vec[0] ;
    for(int i = 0 ; i < n - 1 ; i++){
        if(vec[i] == val  && vec[i+1] == vec[n-1]){
            std :: cout << "YES\n" ;
            vec.clear();
        a.clear();
        b.clear();
            return;
        }
    }
    std :: cout << "NO\n" ;
    vec.clear();
    a.clear();
    b.clear();
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std:: cin >> t;
    while( t--){
        solution();
    }
}