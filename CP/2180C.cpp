#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solution(){
    ll  n , k;
    cin >> n >> k;
    bitset<64> b(n);
    int count = 0;
    int idx = 0;
    if(k % 2 == 1){
        for(int i = 0 ; i < k ; i++){
            cout << n << ' ';
        }        cout << "\n";
        return;
    }
    for(int i = 63 ; i >= 0 ; i--){
        if(b[i]) count ++;
        if(count == 2) {
            idx = i;
            break;
        }
    }
    if(count < 2){
        cout << 0 << ' ';
        for(int i = 0 ; i < k-1 ; i++){
            cout << n << ' ';
        }
        cout << "\n";
        return;
    }
    ll ans = ( 1LL << (idx+1)) - 1;
    cout << ans << ' ';
    cout << ll(n ^ ans) << ' ';
    for(int i = 0 ; i < k-2 ; i++){
        cout << n << ' ';
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--){
            solution();
        }
    }
    return 0;
}