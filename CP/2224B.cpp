#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n;
    std::cin >> n;
    std::vector<ll> v(n);
    for (int i = 0 ; i< n ; i++){
        std::cin >> v[i];
    }
    ll max= *std::max_element(v.begin(),v.end());
    ll ans = 0 ;
    ll mex = 0 ;
    std::set<ll> s;
    std::sort(v.begin(),v.end());
    v.insert(v.begin(),v[n-1]);
    v.pop_back();
    std::cout << "\n";
    for(int i = 0 ; i < n ; i++){
        s.insert(v[i]);
    }
    while(s.count(mex)){
        mex++;
    }
    for(int i = 0 ; i < n ; i++){
        if(i < mex){
            if(i == max){
                i++;
                n++;
            }
            ans += i;
        }else ans += mex;
    }
    ans += v.size()*max ;
    std::cout << ans << "\n";
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