 #include <bits/stdc++.h>
 using namespace std;
 
 bool isValid(string &s) {
        int n=s.size();
        for(int i=0 ; i<n-1;i++){
            if( s[i]=='(' && s[i+1]==')' ){
                s.erase(i,2);
                // cout << s << "\n";
                if(s.empty()) return true;
            //    else return false;
                if(i==0) i--;
                else i-=2; }
            else if(s[i]=='{'&&s[i+1]=='}'){
                s.erase(i,2); 
                    // cout << s << "\n";  
                  if(s.empty()) return true;
                //   else return false;
                   if(i==0) i--;
                   else i-=2; }
            else if(s[i]=='['&&s[i+1]==']'){
                s.erase(i,2 ); 
                    // cout << s << "\n";
                if(s.empty()) return true;
            //    else return false;
                if(i==0) i--;
                else i-=2;  }
        
    }
    if(s.empty()) return true;
        else return false;
 }

int main(){
    string s;
    cin >> s;
    if(isValid(s)){ cout << "Yes\n"; cout << s << "\n";}
    else {cout << "No\n"; cout << s << "\n";}
}