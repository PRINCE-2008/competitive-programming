#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin >> n;
    vector<int> v(4*n+1);
    for(int i = 1 ; i <=n ; i++){
        v[i*2-1] = i;
        v[i*2] = i;
    }
    pair<int, int > p = {1,2};
    int count = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(count == 0 ){
            count++;
            v[2*i-1+2*n] = p.first;
            v[2*i+2*n] = p.second;
        }else if(count == 1){
            count = 0 ;
            v[2*i-1+2*n] = p.first;
            v[2*i+2*n] = p.second;
            p.first+=2;
            p.second+=2;
        }
    }
    for(int i = 1 ; i <= 4*n ; i++){
        cout << v[i] << ' ';
    }
    cout << "\n";
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