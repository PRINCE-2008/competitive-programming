#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void brute_force(vector<ll> v) {
    ll best_ans = -1;
    vector<ll> best_p;
    sort(v.begin(), v.end());
    do {
        ll max_val = 0;
        ll mex_val = 0;
        ll ans = 0;
        set<ll> s;
        for(ll x : v) {
            max_val = max(max_val, x);
            s.insert(x);
            while(s.count(mex_val)) mex_val++;
            ans += max_val + mex_val;
        }
        if(ans > best_ans) {
            best_ans = ans;
            best_p = v;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << "Best sum: " << best_ans << "\n";
    cout << "Perm: ";
    for(ll x : best_p) cout << x << " ";
    cout << "\n";
}

int main(){
    int t;
    if (!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        brute_force(v);
    }
}
