#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin >> n ;
    vector<int> b(n+1);
    for(int i = 1 ; i <= n ; i++) cin >> b[i];
    int m ; cin >> n ;
    vector<int> a(n+1); for(int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
   int  it1 = 1 ;
    int it2 = 1 ;
    int ans = 0 ;
    while(it1 < a.size() && it2 < b.size()){
        if(a[it1] >= b[it2] -1 && a[it1] <= b[it2] + 1){
            it1++ ;
            ans++ ;
            it2++ ;
        } else if(a[it1] < b[it2] - 1){
            it1++ ;
        } else {
            it2++ ;
        }
        // cout << it1 << " " << it2 << " " << ans << endl ;
}
cout << ans << endl ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}