#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , x , y , z;
    cin >> n >> x >> y >> z ;
    float ans = 0 ;
    if( x*z >= n){
        ans = float(n)/(x+y);
    }else{
        ans = min(float(n)/(x+y), z + float(n-x*z)/(x+10*y));
    }
    if(ans - int(ans) == 0){
        cout << int(ans) << "\n";
    } else {
        cout << int(ans) + 1 << "\n";
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