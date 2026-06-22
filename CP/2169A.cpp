#include <bits/stdc++.h>

void solution(){
    int n , a;
    std::cin >> n >> a;
    std::vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        std::cin >> arr[i];
    }
    int lcount = 0;
    int rcount = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] < a){
            lcount++;
        } else if(arr[i] > a){
            rcount++;
        }
    }
    if(lcount >= rcount){
        std::cout << a-1 << "\n";
    }else {
        std::cout << a+1 << "\n";
    }

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