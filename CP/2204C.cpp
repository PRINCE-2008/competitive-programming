#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0; 
    return (a / gcd(a, b)) * b;
}

void solution() {
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    
    for(int i = 0; i < 3; i++) {
        ll ab = lcm(a, b);
        ll ac = lcm(a, c);
        ll abc = lcm(ab, c);
        
        ll ans = 0;
        if (a != 0 && ab != 0 && ac != 0 && abc != 0) {
            ans = 6 * (m / a) - 3 * (m / ab + m / ac) + 2 * (m / abc);
        }
        cout << ans << " ";
        
        ll temp = a;
        a = b;
        b = c;
        c = temp;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solution();
        }
    }
    return 0;
}