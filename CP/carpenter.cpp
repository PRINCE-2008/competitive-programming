#include <bits/stdc++.h>
#define comp(a,b,c) (a+b>c)

void solution(){
    int n;
    std::cin >>n;
    std::vector<int> a(n);
    for(int i=0 ;i<n ;i++) std::cin >> a[i];
    int isTrue = false;
    for(int i=0 ;i<n-1 ;i++){
        int min = std::min(a[i], a[i+1]);
        int max = std::max(a[i], a[i+1]);
        if(comp(min, min, max)){
            isTrue = true;
            break;
        }
    }
    if(isTrue) std::cout << "YES\n";
    else std::cout << "NO\n";
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