#include <bits/stdc++.h>
using namespace std;


void solution(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> query(q);
    for(int i = 0 ; i < q ; i++){
        cin >> query[i];
    }
    int time = 0 ;
    int countB = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'B'){
            countB++;
        }
    }
    if (countB == 0){
        for(int i = 0 ; i < q ; i++){
            cout << query[i] << ' ';
        }
        cout << "\n";
        return ;
    }else for(int i = 0 ; i < q ; i++){
        int k = query[i];
        while(k>0){
            if(s[time%n] == 'A'){
                k--;
                time++;
            }else if(s[time%n] == 'B'){
                k = k/2;
                time++;
            }
        }
        cout << time << "\n";
        time = 0 ;
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