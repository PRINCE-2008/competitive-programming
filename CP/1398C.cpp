#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


void solution() {
    int n ;
    string s;
    cin >> n >> s;
    int prev = 0;
    int curr = 0;
    map<int, ll> m;
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        curr = prev + (s[i] - '0') ;
        prev = curr;
        m[curr - i - 1]++;
    }
    for(auto [key , value] : m){
        if(key == 0){
            ans += value ;
        }
        ans += (value * (value - 1)) / 2 ;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}