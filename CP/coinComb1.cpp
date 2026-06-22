#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];
    int mod = 1000000007 ;
    vector<int> soln(k+1,0);
    soln[0] = 1 ;
    for(int i = 1 ; i <= k ; i++){
        for(auto x : v){
            if(i - x >= 0){
                soln[i] = (soln[i] + soln[i-x])  ;
                if(soln[i] >= mod){
                    soln[i] -= mod ;
                }
            }
        }
    }
    cout << soln[k] << "\n" ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
}