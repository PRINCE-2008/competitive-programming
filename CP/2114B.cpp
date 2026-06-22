#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k;
    string s;
    cin >> n >> k >> s ;
    int C1 = 0 ;
    int C0 = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            C1++;
        } else {
            C0++;
        }
    }
    while(C1 > 0 && C0 >0){
        if(C1/2 + C0/2 > k){
            C1 --;
            C0 --;
        }else {
            break;
        }
    }
    if(C1/2 + C0/2 == k || (C1 == 0 && C0/2 == k) || (C0 == 0 && C1/2 == k)){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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