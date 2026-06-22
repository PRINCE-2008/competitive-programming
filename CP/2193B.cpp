#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , q ;
    cin >> n >> q ;
    vector<int> a(n), b(n);
    for(int i = 0 ; i <n ; i ++) cin >> a[i] ;
    for(int i = 0 ; i <n ; i ++) cin >> b[i] ;
    vector<pair<int,int>> query(q);
    for(int i = 0 ; i < q ; i++) cin >> query[i].first >> query[i].second ;

    if(a[n-1] < b[n-1]){
        a[n-1] = b[n-1];
    }

    for(int i = n-2 ; i >= 0 ; i--){
        if(a[i] < a[i+1]){
            a[i] = a[i+1];
        }
        if(a[i] < b[i]){
            a[i] = b[i];
        }
    }
    vector<int> pSum(n), sSum(n);
    pSum[0] = a[0];
    for(int i = 1 ; i < n ; i++) pSum[i] = pSum[i-1] + a[i];
    sSum[n-1] = a[n-1];
    for(int i = n-2 ; i >= 0 ; i--) sSum[i] = sSum[i+1] + a[i];
    int sum = pSum[n-1];
    for(int i = 0 ; i < q ; i++){
        int l = query[i].first - 2 ;
        int r = query[i].second  ;
        if(l < 0 && r == n){
            cout << sum << " ";
        }else if(l < 0){
            cout << pSum[r-1] << " ";
        }else if(r == n){
            cout << sSum[l+1] << " ";
        }else{
            cout << sum - pSum[l] - sSum[r]  << " ";
        }
    }
    cout << "\n";
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