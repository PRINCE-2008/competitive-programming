#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    int arr[n][2];
    for(int i = 0 ; i< n ;i++){
        std::cin >> arr[i][0] >> arr[i][1];
    }
    std::sort(arr, arr + n, [](const int a[0], const int b[0]) {
        return a[0] < b[0];
    });
    for(int i = 0 ;i<n ;i++){
        if(arr[0][1]<arr[i][1]){
            std::cout << "poor Alex\n" ;
            return;
        }
    }
    std::cout << "Happy Alex\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solution();
}
