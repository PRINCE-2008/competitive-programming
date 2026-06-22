#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a , ll b){
    if(b == 0 ) return  a ;
    return gcd(b, a%b);
}

void solution(){
    ll a, b , k ;
    cin >> a >> b >> k ;
    ll g = gcd(a,b);
    a /= g ;
    b /= g ;
    if(a <= k && b <= k){
        cout << "1\n";
    } else {
        cout << "2\n";
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