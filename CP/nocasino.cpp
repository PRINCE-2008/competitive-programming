#include <bits/stdc++.h>

void solution(){
    int n , k;
    std::cin >>n >> k ;
    std::vector<int> a(n);
    for(int i=0 ;i<n ;i++) std::cin >> a[i];
    //a only contains 0 and 1;
    int count = 0;
    for(int i=0, j=0 ;i<n ;i++){
        if(a[i] == 0){
            j++;
            if(j==k){
                count++;
                j=0;
                i++;
            }
        }
        else j=0;
    }
    std::cout << count << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while( t-- ){
        solution();
    }
}