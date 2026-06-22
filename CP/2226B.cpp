#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

void solution(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int ans = 0 ;
    for(int i = 0 ; i < n-1 ; i++){
        if(gcd(v[i],v[i+1]) == abs(v[i] - v[i+1])){
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}