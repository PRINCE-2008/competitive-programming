// You are given two arrays a(n) and b(n) of size n, and an integer k.
// For a subset S , define its score as: mex(b:i in set S) * sum(a:i in set S)
// where mex is the minimum non-negative integer that is not present in the set of b[i] for i in S.
// Find the maximum score of a subset of {1,2,...,n}. 
#include <bits/stdc++.h>
typedef long long ll;

void solution(){
    int n, k;

    std::cin >> n >> k;
    std::vector<ll> a(n) ;
    std::vector<int> b(n) ;
    for(int i=0 ;i<n ;i++) std::cin >> a[i];
    for(int i=0 ;i<n ;i++) std::cin >> b[i];
//  index of zeros in b(n)
    std::queue<int> q;
    for(int i=0 ;i<n ;i++){
        if(b[i] == 0) q.push(i);
    }
    if(q.empty()){
        std::cout << "0\n";
        return ;
    }
    int sum=0;
    if(k!=1){
        while(!q.empty()){
            int index = q.front();
            q.pop();
            sum+=a[index];
        }

        std::cout << 1*sum << "\n";
    }
    else{
    //finding the mex of the array b(n)
        int mex;
        
        std::vector<int> count(n+1,0);
        for(int i=0 ;i<n ;i++) count[b[i]]++;
        for(int i=0 ;i<=n ;i++){
            if(count[i] == 0){
                mex = i;
                break;
            }
        }
        std::cout << mex*std::accumulate(a.begin(), a.end(), 0LL) << "\n";
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