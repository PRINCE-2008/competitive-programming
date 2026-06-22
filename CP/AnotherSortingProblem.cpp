#include <bits/stdc++.h>
 typedef long long ll;
 typedef std::vector<int> vec;
#define FOR(i,n) for(;i<n ;i++)

void solution(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i=0 ;i<n ;i++) std::cin >> a[i];
    std::set<int> b;
    for(int i=0 , prev = a[i];i<n ;i++){
        if(a[i] >=prev) b.insert(i);
        prev = a[i];
    }
    std::set<int> c;
    bool isGreater = false;
    for(int i=0 , prev = a[0], count=0;i<n ;i++){
        if(b.count(i) == 0) {
            if(count == 0 ) {prev = a[i]; c.insert(i);
            count++;
            if(a[i] > *b.begin()) isGreater = true;
        }
            else if(a[i] >= prev){
                prev = a[i];
                c.insert(i);
            }
            else{
                    std::cout << "No\n";
                    return ;
                }
            }
    
    }//minimum diffrence in elements of b and c should be 1
    int minDiff = INT_MAX;
    if(isGreater){
    for(int i : c){
        auto it = b.lower_bound(i);
        if(it != b.end()) minDiff = std::min(minDiff, abs(a[i]-a[*it]));
         if(it != b.begin()){
            it--;
            minDiff = std::min(minDiff, abs(a[i]-a[*it]));
        }
        if(it != b.begin()){
            it--;
            minDiff = std::min(minDiff, abs(a[i]-a[*it]));
        }
    }
    }else{
        for(int i : b){
        auto it = c.upper_bound(i);
        if(it != c.end()) minDiff = std::min(minDiff, abs(a[i]-a[*it]));
        if(it != c.begin()){
            it--;
            minDiff = std::min(minDiff, abs(a[i]-a[*it]));
        }
    }
    }
    int min2 = INT_MAX;
// minimum difrence between elemnets of b if isGreater is false
    if(isGreater){
        for(int i : b){
        auto it = b.upper_bound(i);
        if(it != b.end()) min2 = std::min(min2, abs(a[i]-a[*it]));
         if(it != b.begin()){
            it--;
            min2 = std::min(min2, abs(a[i]-a[*it]));
        }
    }
    }else{
        for(int i : c){
        auto it = c.upper_bound(i);
        if(it != c.end()) min2 = std::min(min2, abs(a[i]-a[*it]));
    }
    }
    std::cout << minDiff << " " << min2 << "\n";
    if(minDiff <=min2) std::cout << "Yes\n";
    else std::cout << "No\n";
}
 int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin  >> t;
    while( t--){
       solution();
    }
 }
