#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k ;
    string s;
    cin >> n >> k >> s ;
    int C1 = 0;
    int maxC1 = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] ==  '1'){
            if(C1 == 0){
                C1 = 1;
            }
            if(s[i] == '1' && i > 0 && s[i-1] == '1'){
                C1++;
            }
            maxC1 = max(maxC1 , C1);
        }else {
            C1 = 0;
        }
    }
    if(maxC1 >= k ){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> a(n);
    int num = n;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '0'){
            a[i] = num;
            num--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
            a[i] = num;
            num--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
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