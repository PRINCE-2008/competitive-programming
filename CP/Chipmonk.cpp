#include <bits/stdc++.h>
typedef long long ll;
// #define comp(a,b) (!(a==b||a+1==b))
#define FOR(i,n) for(int i=0;i<n ;i++)
int solution(std::vector<ll> &nums){
    // Implementation for the solution function
    // Add your implementation here
    int n = nums.size();
    ll min_num = *std::min_element(nums.begin(), nums.end());
    int count = 0;
    FOR(i,n){
        if(!(nums[i] == min_num )){
            ll a;
            if(min_num%2==0) a=min_num;
            else a=min_num+1;
            while(a<nums[i]){
                if(nums[i]%2==0) count++;
                else{
                    nums[i]++;
                    count++;
                    i--;
                    break;
                }
                nums[i]=nums[i]/2;
                if(nums[i]<a){
                    min_num=a=nums[i];
                    if(a%2==0) a=a;
                    else a=a+1;
                    i=-1;
                    break;
                }
            }
            // FOR(j,n){
            //     std::cout << nums[j] << " ";
            // }
            // std::cout << "\n";
        }
    }
    int counter=0;
    FOR(i,n){
        if(nums[i]%2!=0) counter++;
    }
    if(counter==n) return count;
    else return std::min(count+counter,count + n -counter);
    // return count;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int n , count=0;
        std::cin >> n;
        std::vector<ll> nums(n);
        for(int i=0 ;i<n ;i++) std::cin >> nums[i];
        std::cout << solution(nums) << "\n";
    }
}