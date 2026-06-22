#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    set<int> s;
    int count_zero = 0 ;
    for(int i = 0 ; i < n ;i++){
        int x;
        cin >> x;
        if(x == 0){
            count_zero++;
        }
        s.insert(x);
    }
    int mex = 0 ;
    while(s.count(mex)){
        mex++;
    }
    if(mex == 0 || (mex == 1 && count_zero > 1)){
        cout << "NO\n";
    }else {
        cout << "YES\n";
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