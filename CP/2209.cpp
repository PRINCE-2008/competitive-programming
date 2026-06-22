#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0 ; i <n ; i++){
        int greater = 0 ;
        int lesser = 0 ;
        for(int j = i ; j < n ; j++){
            if(a[j] > a[i]){
                greater++;
            }
            else if(a[j] < a[i]){
                lesser++;
            }
            }
            cout << max(greater,lesser) << " ";

    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solution();
        cout << "\n";
    }
}