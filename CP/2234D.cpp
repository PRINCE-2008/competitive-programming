#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t i128;
ll dp1[35][2][2];
ll dp2[35][2][2][2][2];
void pre() {
    for (int u = 0; u < 2; u++) {
        for (int v = 0; v < 2; v++) {
            dp1[0][u][v] = u + v;
            for (int u2 = 0; u2 < 2; u2++) {
                for (int v2 = 0; v2 < 2; v2++) {
                    dp2[0][u][v][u2][v2] = (u * u2) + (v * v2);
                }
            }
        }
    }
    for (int step = 1; step <= 30; step++) {
        for (int u = 0; u < 2; u++) {
            for (int v = 0; v < 2; v++) {
                int mid = u ^ v;
                // Sum of left half + right half - midpoint (to avoid double counting)
                dp1[step][u][v] = dp1[step-1][u][mid] + dp1[step-1][mid][v] - mid;
                
                for (int u2 = 0; u2 < 2; u2++) {
                    for (int v2 = 0; v2 < 2; v2++) {
                        int mid2 = u2 ^ v2;
                        dp2[step][u][v][u2][v2] = dp2[step-1][u][mid][u2][mid2] + 
                                                  dp2[step-1][mid][v][mid2][v2] - 
                                                  (mid * mid2);
                    }
                }
            }
        }
    }
}

void pr(i128 n) {
    if (n == 0) { 
        cout << 0 << "\n"; 
        return; 
    }
    if (n < 0) { 
        cout << '-'; 
        n = -n; 
    }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}

void solution() {
    ll n, k;
    cin >> n >> k;
    string s, z;
    cin >> s >> z;

    ll C[2][2] = {0};
    for (int i = 0; i < n; i++) {
        int u = s[i] - '0';
        int v = z[i] - '0';
        C[u][v]++;
    }

    i128 sum_x = 0;
    for (int u = 0; u < 2; u++) {
        for (int v = 0; v < 2; v++) {
            sum_x += (i128)C[u][v] * dp1[k][u][v];
        }
    }

    i128 sum_xx = 0;
    for (int u1 = 0; u1 < 2; u1++) {
        for (int v1 = 0; v1 < 2; v1++) {
            for (int u2 = 0; u2 < 2; u2++) {
                for (int v2 = 0; v2 < 2; v2++) {
                    sum_xx += (i128)C[u1][v1] * C[u2][v2] * dp2[k][u1][v1][u2][v2];
                }
            }
        }
    }

    i128 ans = (i128)n * sum_x - sum_xx;
    pr(ans);
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        pre();
    
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}