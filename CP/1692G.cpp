#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

void solution(){
    int n , k;
    cin >> n >> k ;
    vector<int> v(n+1,0);
    for(int i = 1 ; i <= n ; i++) cin >> v[i];
    int count = 0 ;
    int ans = 0 ;
    for(int i = 1 ; i <= n-k ; i++){
        for(int j = i ; j < n ; j++){
            if(v[j] < 2*v[j+1]){
                count++;
            } else {
                i = j ;
                break ;
            }
            if(j == n-1){
                i = j ;
            }}
            if(count >= k){
                ans += count - k + 1 ;
                count = 0 ;
            }
            else {
                count = 0 ;
            }
        }
    
    cout << ans << endl;
}

int main(){
    FastIO();
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}