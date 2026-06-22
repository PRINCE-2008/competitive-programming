#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k;
    cin >> n >> k ;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int ans = 0 ;
    int left = n-1 , right = n-1 ;
    while(left >= 0 && right >= 0){
        if(v[left]*(right-left+1) >= k){
            ans ++ ;
            right = left - 1 ;
            left-= 1 ;
        }else {
            left-- ;
        }
    }
    cout << ans << "\n" ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}