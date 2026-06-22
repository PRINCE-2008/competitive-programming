#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n , k ;
    cin >> n >> k ;
    int score = 0;
    int position = 0;
    int pret= 0;
    int p = 0;
    for(int i = 0 ; i < n ; i++){
        int t;
        cin >> t ;
        cin >> p ;
        score += t - pret - 1;
        if((t-pret)%2 == 0){
            position = (position == 0) ? 1 : 0;
        }
        if(position != p){
            score++;
            position = p;
        }
        pret = t;
    }
    score += (k - pret);
    cout << score << "\n";
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