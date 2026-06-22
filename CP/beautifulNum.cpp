#include <bits/stdc++.h>

int solution(){
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> freq(10,0);
    for(char c : s) freq[c - '0']++;
    freq[s[0]-'0']--;
    int sum = s[0] - '0';
    int freqcount = 1;
    for(int i=0 ;i<10 ;i++) {
        
        if(freqcount == n) break;
        sum += i*freq[i];
        freqcount += freq[i];
        // std::cout <<freqcount<<'\n';
        if(sum > 9){
            sum -= i*freq[i];
            freqcount -= freq[i];
            while(sum <= 9 ){
                sum += i;
                freqcount++;
                
            }
            freqcount--;
            break;
        }
    }
    int a = n-freqcount;
    sum = 1;
    freqcount = 0;
    for(int i=0 ;i<10 ;i++) {
        if(freqcount == n-1) break;
        // std::cout <<freqcount<<'\n';
        sum += i*freq[i];
        freqcount += freq[i];
        // std::cout <<freqcount<<'\n';
        if(sum > 9){
            sum -= i*freq[i];
            freqcount -= freq[i];
            while(sum <= 9 ){
                sum += i;
                freq[i]--;
                freqcount++;
            }
            freqcount--;
            break;
        }
    }
    int b = n-freqcount;
    return std::min(a,b);

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
   
    while(t--){
        std::cout << solution() << "\n";
    }
}