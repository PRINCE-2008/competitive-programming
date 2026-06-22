#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n;
    cin >> n ;
    string s;
    cin >> s ;
    // this is the which uses hashing
    // int prevHash = 0 ;
    // int currentHash = 0 ;
    // int ans = 0 ;
    // for(int i = 0 ; i < n-1 ; i++){
    //     currentHash = (s[i]-'0') + (s[i+1]-'0') ;
    //     if(currentHash != prevHash){
    //         ans++;
    //     }
    //     prevHash = currentHash;
    // }
    // here is the another approah
    int red = 0 ;
    int ans = 0 ;
    for(int i = 1 ; i < n-1 ; i++){
        if(s[i-1] == s[i+1]){
            red++;
        }
    }
    ans = n - 1 - red ;
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