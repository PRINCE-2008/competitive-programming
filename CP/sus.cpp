#include <bits/stdc++.h>

void solution(){
    std::string s;
    std::cin >> s;
    int n = s.size();
    int count =0;
    if(s[0]=='u') {
        count ++;
        s[0]='s';
    }
    if(s[n-1]=='u'){
        count ++;
        s[n-1] = 's';
    }
    int winSize = 0;
    for(int i = 0 ; i < n ; i ++){
        if(s[i] == 'u') {
            winSize++;
        }
        else{
            count+= winSize/2;
            winSize=0;
        }
    }
    std::cout << count << '\n' ;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t ;
    while (t--){
        solution();
    }
}