#include <bits/stdc++.h>
using namespace std;

void solution(){
    int a , b , n;
    cin >> a >> b >> n ;
    float len = min(float(b), float(a)/float(n));
    bool flag = false ;
    // for(int i = 1 ; i < n+1 ; i++){
    //     if(len*i == float(b)){
    //         flag = true ;
    //         break;
    //     }
    // }
    // if(flag){
    //     if(len < float(b)){
    //         cout << 2 << "\n";
    //     }else {
    //         cout << 1 << "\n";
    //     }
    // } else {
    //     cout << 2 << "\n";
    // }
    if( n > float(a)/float(b) && b !=a ){
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
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