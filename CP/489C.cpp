#include <bits/stdc++.h>
using namespace std;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);


void solution(){
    int n , k ;
    cin >> n >> k ;
    string a(n,'0');
    int sum = 0 ; 
    int lastidx = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 9 ; j !=0 ; j--){
            if(sum + j <= k){
                sum += j ;
                a[i] = j + '0' ;
                lastidx = i ;
                break;
            }
            if(sum == k){
                break;
            }
        }
    }
    if(sum < k){
        cout << -1 << ' ' << -1 << "\n";
        return;
    }
    string b = a ;
    if(lastidx == n-1 ){
        reverse(a.begin(),a.end());
        cout << a << ' ' << b << "\n";
        return;
    }
    if(lastidx == 0  && sum <= 1){
        if(sum == 0 && n > 1 ) {cout << -1 << ' ' << -1 << "\n";   return;
        }
        // else if(sum == 1 ) exit(0);
        else if(sum == 0 && n == 1) {cout << 0 << ' ' << 0 << "\n"; return;}
    }
    sort(b.begin(),b.end());
    a[lastidx] = a[lastidx] - 1 ;
    a[n-1] = '1' ;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    cout << a << ' ' << b << "\n";
    
    return;
}

int main(){
    FastIO();
    solution();
}