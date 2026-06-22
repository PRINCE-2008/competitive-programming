#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    std::vector< int >  a(n);
    for( int i=0 ; i<n ; i++) std::cin >> a[i];
    std::map<int,int> m;
    int sum=0;
    for(int i=0 ;i<n ;i++){
        if(i!=n-1) sum+=abs(a[i]-a[i+1]);
        if(i==0) m[i] = -abs(a[i]-a[i+1]);
        if(i==n-1) m[i] = -abs(a[i]-a[i-1]);
        if(i>0 && i<n-1){
            int min = std::min(abs(a[i]-a[i-1])+ abs(a[i]-a[i+1]),abs(a[i-1]-a[i+1]));
            if(min == abs(a[i-1]-a[i+1]))
            m[i] = -abs(a[i]-a[i-1]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]);
        }
    }
    int minSum = sum;
    for(auto [key , value] :m){
        minSum = std::min(minSum, sum + value);
    }
    std::cout << minSum << "\n";

}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--){
        solution();
    }

}