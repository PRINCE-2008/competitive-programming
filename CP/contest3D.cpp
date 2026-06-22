#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int min = a[0];
    int second_min ;
    for(int i = 0 ; i < n ; i++){
        if(a[i] != min){
            second_min = a[i];
            break;
        }
    }
    int ans = min;
    while(second_min - ans > min){
        ans = second_min - min;
    }
    cout << ans << "\n";
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