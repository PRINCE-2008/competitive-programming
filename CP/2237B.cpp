#include <bits/stdc++.h>

using namespace std;

bool isSort(vector<int>& a){
    for(int i = 1 ; i < a.size() ; i++){
        if(a[i] < a[i-1]){
            return false ;
        }
    }
    return true ;
}

void solution(){
    int n ; cin >> n;
    vector<int> a(n+1), b(n+1);
    set<int> s;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> b[i];
    }
    vector<int> c = a;
    sort(c.begin(),c.end());
    for(int i = 1 ; i <= n ; i++){
        if(c[i] >= b[i]){
            cout << -1 << endl;
            return ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(a[j] < b[i]){
                a[j] = b[i];
                if(j < n-1){
                    i++;
                }
            }
        }
    }
    
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(isSort(a)){
            break ;
        }else {
        for(int i = 1 ; i < n ; i++){
            if(isSort(a)){
                break ;
            }else {
                if(a[i] > a[i+1]){
                    ans++;
                    swap(a[i],a[i+1]);
            }
        }}
       }
    }
    cout << ans << endl;
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