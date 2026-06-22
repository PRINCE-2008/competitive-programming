#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



void solution(){
    int n ;
    cin >> n;
    vector<ll> a(n) , b(n+1);
    int num = 1;
    int i = 0 ;
    a[0] = 1;
    while(i<n){
        bool flag = true;
        for(int in = 2 ; in*in <= num ; in++){
            if(num%in == 0 ){
                flag = false;
                break;
            }
        }
        if(flag){
            a[i] = num;
            i++;
            num++;
        }
        num++;
    }
    b[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        b[i] = a[i-1]*a[i];
    }
    for(int i = 0 ; i < n ; i++){
        cout << b[i] << " ";
    }
    cout << "\n";
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