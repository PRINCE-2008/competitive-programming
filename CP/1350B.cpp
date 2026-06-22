#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> v[i];
    vector<int> dp(n+1, 1);
    for(int i = 1 ; i <= n ; i++)
        for(int j = i*2 ; j <= n ; j+=i)
            if(v[j] > v[i]) dp[j] = max(dp[j], dp[i]+1);
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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