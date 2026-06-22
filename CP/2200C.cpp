#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    stack<char> m;
    for(int i = 0 ; i < n ; i++){
        char c ;
        cin >> c;
        if(m.empty()){
            m.push(c);
        }
        else{
            if(m.top() == c){
                m.pop();
            }
            else{
                m.push(c);
            }
        }
    }
    if(m.empty()){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    m.empty();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}