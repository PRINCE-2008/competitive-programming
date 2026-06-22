#include <bits/stdc++.h>
using namespace std;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define ll long long

void solution(){
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    if(n >= 2){
        for(int i = 0 ; i < n ; i++){
            cout << "2" << ' ';
        }
        cout << "\n";
    }
    return;
}


int main(){
    FastIO();
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}