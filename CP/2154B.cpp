#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int currMax = a[0];
    for(int i = 1 ; i < n ; i++){
        if(a[i] > currMax){
            currMax = a[i];
        }else if(i%2 == 1){
            a[i] = currMax;
        }
    }
    int ans = 0 ;
    for(int i = 1 ; i < n ; i+=2){
        if(a[i-1] >= a[i]){
            ans += a[i-1] - a[i] + 1 ;
            a[i-1] = a[i] -1 ;
        }
        if(a[i+1] >= a[i] && i!= n-1){
            ans += a[i+1] - a[i] + 1 ;
            a[i+1] = a[i] -1 ;
        }
    }
    cout << ans << "\n";
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