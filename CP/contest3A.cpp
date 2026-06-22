#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n = 0 ;
    cin >> n ;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 1 ; i < n-1 ; i++){
        if(a[i] == -1){
            a[i] = 0 ;
        }
    }
    if(a[0] == -1 && a[n-1] != -1){
        a[0] = a[n-1];
    }else if(a[n-1] == -1 && a[0] != -1){
        a[n-1] = a[0];
    } else if(a[0] == -1 && a[n-1] == -1){
        a[0] = 0 ;
        a[n-1] = 0 ;
    }
    vector<int> b(n-1);
    for(int i = 0 ; i < n-1 ; i++){
        b[i] = a[i+1] - a[i];
    }
    cout << abs(accumulate(b.begin(),b.end(),0)) << "\n";
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << ' ';
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