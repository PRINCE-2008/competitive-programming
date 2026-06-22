#include <bits/stdc++.h>
using namespace std;
void solution(){
    int n , k ;
    cin >> n >> k ;
    set<int> s;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    for(int i = 0 ; i < k ; i++){
        if(s.count(i)){
            ans++;
        }
    }
    if(k == 0 && s.cout(0)){
        
    }
    cout << k - ans << "\n";
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