#include <iostream>
#include <string>
using namespace std;


bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        int n= s2.size();
        int size=s1.size();
        for(int i=0 ; i< size ;i++){
            freq[s1[i] - 'a']++;
        }
         int winFreq[26]={0};
        for(int i = 0; i< n-size+1; i++){
           
            if(i==0){
                for(int j = 0 ; j<size; j++){
                    winFreq[s2[j]-'a']++;
                }
            }else winFreq[s2[i+size-1]-'a']++;
            for(int k=0 ;k<26 ;k++){
                if(freq[k]!=winFreq[k]) break;
                if(k==25) return true;
            }
            winFreq[s2[i]-'a']--;
        }
        return false;
    }

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    if(checkInclusion(s1, s2)) cout << "Yes\n";
    else cout << "No\n";
}

string reverseWords(string s) {
            int n= s.size();
            string word ;
            string renew;
            bool isempty=true;
            for(int i= 0 ;i<n ;i++){
                if(s[n-i-1]==' '&& isempty==false) {
                    isempty=true;
                    renew+=word;
                    renew+=" ";
                    word.erase(); word.clear();}
                else if(s[n-i-1]!=' '){
                    if(i==n-1 && isempty==false) renew+=word;
                    isempty=false;
                    word.insert(word.begin(),s[n-i-1]);
                }
            }
            if(renew.back()==' ') renew.pop_back();
            return renew;
            
    }