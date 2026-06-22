#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solution(){
    int n;
    cin >> n ;
    vector<int> p(n) , s(n);
    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    if(p[n-1] != s[0]){
        cout << "NO\n";
        return;
    }
    int g = p[n-1];
    for(int i = 0 ; i < n-1 ; i++){
        if((gcd(p[i], p[i+1]) != p[i+1])&&(gcd(s[n-1-i], s[n-1-(i+1)]) != s[n-1-(i+1)])&&(gcd(p[i], s[i+1]) != g)&&(gcd(s[i], p[i+1]) != g)){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(gcd(gcd(p[i], s[j]), g) != g){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--){
            solution();
        }
    }
    return 0;
}