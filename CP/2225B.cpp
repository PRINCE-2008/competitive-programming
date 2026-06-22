#include <bits/stdc++.h>
using namespace std;

void solution(){
    string s;
    cin >> s;
    int n = s.size();
    int left = 0 , right = n - 1;
    bool cond1 = true , cond2 = true;
    while ((cond1 || cond2) && left < right){
           if(cond1) if((s[left] != s[left +1])){
                left ++;
            }else {
                left ++;
                cond1 = false;
            }
            if(cond2) if((s[right] != s[right - 1])){
                right --;
            }else {
                right --;
                cond2 = false;
            }
        
    }
    if (left >= right) cout << "YES\n";
    else{
        for(int i = left ; i <= right-1 ; i++){
            if(s[i] == s[i +1 ] ){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}
