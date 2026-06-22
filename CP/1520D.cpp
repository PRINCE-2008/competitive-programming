#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solution(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;

    map<int,int> m;

    for(int i = 0 ; i < n ; i++){
        m[v[i]-i]++;
    }

    ll ans = 0 ;
    for(auto [key,value] : m){
        ll count = value;
        count = (count * (count-1))/2 ;
        ans +=  count;
    }
    cout << ans << endl;
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