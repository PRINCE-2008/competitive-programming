#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    ll n ;
    cin >> n ;
    ll ten = 10 ;
    vector<ll> ans;
    while(ten + 1 <= n){
        if(n % (ten + 1) == 0){
            ll temp = n / (ten + 1);
            ans.push_back(temp);
        }
        ten *= 10;
    }
    if(ans.empty()){
        cout << "0\n";
    } else {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(ll x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }
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