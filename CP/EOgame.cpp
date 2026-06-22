#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solution(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());
    ll alex = 0;
    ll bob = 0;
    for(int i = 0 ; i < n ; i++){
        if(i % 2 == 0){
            if(a[i] % 2 == 0){
                alex += a[i];
            }
        }
        else {
            if(a[i] % 2 == 1){
                bob += a[i];
            }
        }
    }
    if(alex > bob){
        cout << "Alice\n";
    } else if(bob > alex){
        cout << "Bob\n";
    } else {
        cout << "Tie\n";
    }
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