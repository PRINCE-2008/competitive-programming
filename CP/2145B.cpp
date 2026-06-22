#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k;
    cin >> n >> k ;
    string s;
    cin >> s;
    string v(n,'+');
    int count0 = 0 ;
    int count1 = 0 ;
    int count2 = 0 ;
    for(int i = 0 ; i < k ; i++){
        if(s[i] == '0'){
            count0++;
        } else if(s[i] == '1'){
            count1++;
        } else {
            count2++;
        }
    }
    if(k == n){
        cout << string(n,'-') << "\n";
        return;
    }
    for(int i = 0 ; i < count0 ; i++){
        v[i] = '-';
    }
    for(int i = 0 ; i < count1 ; i++){
        v[n-1-i] = '-';
    }
    for(int i = 0 ; i < count2 ; i++){
        if(v[i+count0] != '-'){
            v[i+count0] = '?';
        } 
        if(v[n-1-count1-i] != '-'){
            v[n-1-count1-i] = '?';
        }
    }
    cout << v << "\n";
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