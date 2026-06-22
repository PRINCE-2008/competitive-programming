#include <bits/stdc++.h>

void solution(){
    int n ;
    std::string s;
    std::cin >> s;
    n = s.size();
    int count = 0;
    bool isStart = false;
    for(int i=0 ;i<n ;i++){
        if(!isStart ){
            if(s[i]=='0') {
                isStart = true;
                count++;}
        }else if(s[i]=='1') {
             isStart = false;
    }
}
   if(count>=2) std::cout << 2 << "\n";
    else if(count==1) std::cout << 1 << "\n";
    else std::cout << 0 << "\n";
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        solution();
    }

}