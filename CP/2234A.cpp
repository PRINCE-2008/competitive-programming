#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // for reverse sorting
    sort(a.begin(), a.end(), [] (int x, int y) {
        return x > y;
    });
    if(n == 2){
        cout << a[0] << " " << a[1] << "\n";
        return;
    }
    for(int i = 2 ; i < n ; i++){
        if(a[i] != a[i-2]%a[i-1]){
            cout << -1 << "\n";
            return;
        }
    }
    cout << a[0] << " " << a[1] << "\n";
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