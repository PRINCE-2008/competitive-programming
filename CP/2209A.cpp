#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n;
    ll curr;
    int k;
    std::cin >> n >> curr >> k;
    std::vector<ll> v(n);
    for(int i = 0 ; i< n ;i++){
        std::cin >> v[i];
    }
    std::sort(v.begin(),v.end());
    
    for(int i = 0 ; i<n ; i++){
        if(curr<v[i]){
            std::cout << curr << "\n";
            return;
        }
        else{
            if(v[i] + k > curr){
                k = k - (curr - v[i]);
                curr += curr;
                v[i] = curr;
            }else{
                v[i] += k;
                curr += v[i];
                k = 0 ;
            }
        }
    }
    std::cout << curr << "\n";
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